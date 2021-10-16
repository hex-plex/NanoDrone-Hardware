#include<stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"


#define CHANNEL_NUMBER 6  //set the number of chanels
#define CHANNEL_DEFAULT_VALUE 1500  //set the default servo value
#define FRAME_LENGTH 22500  //set the PPM frame length in microseconds (1ms = 1000µs)
#define PULSE_LENGTH 300  //set the pulse length
#define onState 1         //set polarity of the pulses: 1 is positive,
#define offState 0        // 0 is negative
#define sigPin 11         //set PPM signal output pin
#define TRUE 1
#define FALSE 0  

int64_t ppm[CHANNEL_NUMBER];

int64_t alarm_callback(alarm_id_t id, void *user_data){

	static bool state = TRUE;
	
	if (state) {  //start pulse
		gpio_put(sigPin, onState);
    	state = FALSE;
    	return (PULSE_LENGTH * 2); //(callback again triggered in returned value (microseconds))
	  } 
  	
	else {       //end pulse and calculate when to start the next pulse
    	static int64_t cur_chan_numb;
    	static int64_t calc_rest;
    	gpio_put(sigPin, offState);
    	state = TRUE;

    	if(cur_chan_numb >= CHANNEL_NUMBER){
      		cur_chan_numb = 0;
      		calc_rest = calc_rest + PULSE_LENGTH;
      		int64_t next_pulse = (FRAME_LENGTH - calc_rest) * 2;
      		calc_rest = 0;
      		return next_pulse; //(callback again triggered in next_pulse microseconds)
    	   }
    	else{
      		int64_t next_pulse = (ppm[cur_chan_numb] - PULSE_LENGTH) * 2;
      		calc_rest = calc_rest + ppm[cur_chan_numb];
      		cur_chan_numb++;
      		return next_pulse; //(callback again triggered in next_pulse microseconds)
    		}     
  		}		
}


int main(){
	
	stdio_init_all();
	gpio_init(sigPin);
	gpio_set_dir(sigPin, GPIO_OUT);
	
	for(int i=0; i<CHANNEL_NUMBER; i++){
      ppm[i]= CHANNEL_DEFAULT_VALUE;
	  }
	
	gpio_put(sigPin, offState);
	
	add_alarm_in_ms(100, alarm_callback, NULL, FALSE);
	
	while(1){	
		/*
    Here modify ppm array and set any channel to value between 1000 and 2000. 
    Timer running in the background will take care of the rest and automatically 
    generate PPM signal on output pin using values in ppm array
  	*/
  	tight_loop_contents();
	}	

}
