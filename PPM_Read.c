#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define RX_PIN 12
#define CHANNEL_NUMBER 6

int64_t ch[CHANNEL_NUMBER +1], t[CHANNEL_NUMBER + 2];
int64_t pulse = 0;

void irq_callback(uint gpio, uint32_t events){
	
	t[pulse] = time_us_64();
	
	switch(pulse){
		case 1 : 
		ch[1] = t[1] - t[0];
		pulse++;
		if (ch[1] > 3000){
			t[0] = t[1];
			pulse = 1;
		}
		break;
		
		case 2 : 
		ch[2] = t[2] - t[1];
		pulse++;
		if (ch[2] > 3000){
			t[0] = t[2];
			pulse = 1;
		}
		break;
		
		case 3 : 
		ch[3] = t[3] - t[2];
		pulse++;
		if (ch[3] > 3000){
			t[0] = t[3];
			pulse = 1;
		}
		break;
		
		case 4 : 
		ch[4] = t[4] - t[3];
		pulse++;
		if (ch[4] > 3000){
			t[0] = t[4];
			pulse = 1;
		}
		break;
		
		case 5 : 
		ch[5] = t[5] - t[4];
		pulse++;
		if (ch[5] > 3000){
			t[0] = t[5];
			pulse = 1;
		}
		break;
		
		case 6 : 
		ch[6] = t[6] - t[5];
		pulse++;
		if (ch[6] > 3000){
			t[0] = t[6];
			pulse = 1;
		}
		break;
		
		case 7 :
		ch[0] = t[7] - t[6];
		pulse ++;
		if (ch[0] > 3000){
			t[0] = t[7];
			pulse = 1;
		}
		default : 
		pulse++;
		break;		
		
	}
	
}

int main(){
	
	gpio_init(RX_PIN);
	gpio_set_dir(RX_PIN, GPIO_IN);
	gpio_pull_up(RX_PIN);
	gpio_set_irq_enabled_with_callback(RX_PIN, 0x08, 1, irq_callback);
	
	while(1){
		
		for(int i = 0; i < (CHANNEL_NUMBER + 1); i++){
			printf("%d  -  ", ch[i]);
		}
		tight_loop_contents();
	}	
}