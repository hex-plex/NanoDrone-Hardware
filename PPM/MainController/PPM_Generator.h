#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#define CHANNEL_NUMBER 6  //set the number of chanels
#define FRAME_LENGTH 22500  //set the PPM frame length in microseconds (1ms = 1000µs)
#define PULSE_LENGTH 300  //set the pulse length
#define onState 1         //set polarity of the pulses: 1 is positive,
#define offState 0        // 0 is negative
#define TRUE 1
#define FALSE 0  

int channel_default_value[CHANNEL_NUMBER] = 1500;

int sigPin=11;

uint32_t computed_trans_time;
int64_t cur_chan_numb=0;
int64_t calc_rest=0;
bool state = TRUE;
int64_t ppm[CHANNEL_NUMBER];
int64_t time_started = 0;
int64_t time_called = 0;
int64_t time_taken = 0;

int64_t alarm_callback(alarm_id_t id, void *user_data){
//static bool state = TRUE;
    time_called = time_us_64();
    time_taken = time_called - time_started;
    //printf("Callback Triggered in %d (micros)(cpu_time)\n", (uint32_t)time_taken);
    if (state) {  //start pulse
        //printf("start pulse \n");
        gpio_put(sigPin, onState);
        computed_trans_time = (PULSE_LENGTH * 2);
            state = FALSE;
        //(callback again triggered in returned value (microseconds))
    } 
    
    else {       //end pulse and calculate when to start the next pulse
        gpio_put(sigPin, offState);
        state = TRUE;
        //printf("pause pulse \n");
        if(cur_chan_numb >= CHANNEL_NUMBER){
            cur_chan_numb = 0;
            calc_rest = calc_rest + PULSE_LENGTH;
            //int64_t next_pulse = 
            computed_trans_time = (FRAME_LENGTH - calc_rest) * 2;
            calc_rest = 0;
            //return next_pulse; //(callback again triggered in next_pulse microseconds)
        }else{
            //int64_t next_pulse = 
            computed_trans_time = (ppm[cur_chan_numb] - PULSE_LENGTH) * 2;
            calc_rest = calc_rest + ppm[cur_chan_numb];
            cur_chan_numb++;
            //return next_pulse; //(callback again triggered in next_pulse microseconds)
        }     
    }
    
    //printf("Callback triggered in %d (micros)(computed) \n", computed_trans_time/2);
    time_started = time_us_64();
    return (int64_t)(computed_trans_time/2);	
}

class PPMGen{
    public:
        PPMGen();
        PPMGen(int);
        void setValue(int* inp);
};

PPMGen::PPMGen(){
    gpio_init(sigPin);
	gpio_set_dir(sigPin, GPIO_OUT);
    for(int i=0; i<CHANNEL_NUMBER; i++){
        ppm[i]= channel_default_value[i];
	}
    gpio_put(sigPin, offState);
	computed_trans_time = 100;
	add_alarm_in_us(computed_trans_time/2, alarm_callback, NULL, FALSE);
	
}

PPMGen::PPMGen(int selectPin){
    sigPin = selectPin;
    gpio_init(sigPin);
	gpio_set_dir(sigPin, GPIO_OUT);
    for(int i=0; i<CHANNEL_NUMBER; i++){
        ppm[i]= channel_default_value[i];
	}
    gpio_put(sigPin, offState);
	computed_trans_time = 100;
	add_alarm_in_us(computed_trans_time/2, alarm_callback, NULL, FALSE);
}

PPMGen::PPMGen(int selectPin, int* cha_default){
    sigPin = selectPin;
    
    for(int i=0; i<CHANNEL_NUMBER; i++){
        channel_default_value[i] = cha_default[i];
	}

    gpio_init(sigPin);
	gpio_set_dir(sigPin, GPIO_OUT);
    for(int i=0; i<CHANNEL_NUMBER; i++){
        ppm[i]= channel_default_value[i];
	}
    gpio_put(sigPin, offState);
	computed_trans_time = 100;
	add_alarm_in_us(computed_trans_time/2, alarm_callback, NULL, FALSE);
}

void setValue(int* inp){
    for(int i=0; i<CHANNEL_NUMBER;i++){
        ppm[i] = inp[i];
    }
}