

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "hardware/timer.h"

#include "hardware/irq.h"
#include "pico/multicore.h"
#include <string.h>
// #include <iomanip>
// using namespace std;

//******************************************************************************[PPM]*********************************************************************************//

#define CHANNEL_NUMBER 6  //set the number of chanels
#define FRAME_LENGTH 22500  //set the PPM frame length in microseconds (1ms = 1000µs)
#define PULSE_LENGTH 300  //set the pulse length
#define onState 1         //set polarity of the pulses: 1 is positive,
#define offState 0        // 0 is negative
#define TRUE 1
#define FALSE 0

int channel_default_value = 1500;

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
static bool state = TRUE;
    // multicore_fifo_push_blocking(123);
 
    // uint32_t g = multicore_fifo_pop_blocking();
 
    // if (g != 123)
    //     printf("Hmm, that's not right on core 1!\n");
    // else
    //     printf("Its all gone well on core 1!");

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
void callback(){
    add_alarm_in_us(computed_trans_time/2, alarm_callback, NULL, FALSE);
    

    while (1)
        tight_loop_contents();
}


// class PPMGen {
//     public:
//         PPMGen(){
//             //printf("started");
            
//             gpio_init(sigPin);
//             gpio_set_dir(sigPin, GPIO_OUT);
//             for(int i=0; i<CHANNEL_NUMBER; i++){
//                 ppm[i]= 1500;
//         }
//             gpio_put(sigPin, offState);
//             computed_trans_time = 100;
//             multicore_launch_core1(callback);
//             //add_alarm_in_us(computed_trans_time/2, alarm_callback, NULL, FALSE);
    
//         }
//         // PPMGen(int);
//         // void setValue(int* inp);
// };
void ppm_init(){

    gpio_init(sigPin);
    gpio_set_dir(sigPin, GPIO_OUT);
    for(int i=0; i<CHANNEL_NUMBER; i++){
        ppm[i]= 1500;
        
    }
    gpio_put(sigPin, offState);
    computed_trans_time = 100;
    multicore_launch_core1(callback);
    //add_alarm_in_us(computed_trans_time/2, alarm_callback, NULL, FALSE);

}



//**********************************************************************************************************//















//#define WIFISSID "jsparrow_2.4Ghz" // wifi SSID
//#define WIFIPASS "happy@123" // wifi password

#define WIFISSID "No" // wifi SSID
#define WIFIPASS "abcdq1987654" // wifi password
#define STATICIP "192.168.1.5" // static IP for PicoWebServer
#define server_port 9999
bool read_sync;


void uart_flush(int ind){
  switch(ind){
    case 0:
      while(uart_is_readable(uart0)){
        uart_getc(uart0);
      }
      break;
    case 1:
      while(uart_is_readable(uart1)){
        uart_getc(uart1);
      }
      break;
  }
}

void parse_input(char* buf){
  //buf;
  int i=0, k = 0;
  int n = strlen(buf);
  while(i<n){
    if(buf[i]=='$')
    {
      i++;
      break;
    }
    i++;
  }
  for (int j=i;j<n;j+=3 ){
  
    char subtext[4];

    memcpy(subtext,&buf[j],3);
    subtext[3] = '\0';
    int var = atoi(subtext);
    if(k<6){
      ppm[k]=var+1000;
    }
    else{
      break;
    }
    // printf("\n%d@",var);
    k++;
    

  }


}



void fetch_Resp(char* buf, const uint32_t waitTime){
  // char buf[512] = "";
  //printf("%d\n", waitTime);
  int64_t prev_time = time_us_64();
  //uint32_t i=0;
  while((int64_t)(time_us_64() - prev_time) < (int64_t)(waitTime)){
    //printf("%ld, %d |", (long)(time_us_64()-prev_time), waitTime);
   
    if(uart_is_readable_within_us(uart0,10000)){
      char re = uart_getc(uart0);
      // printf("%c", re);
      // if ((int)re >123 ||(int)re < 33){continue;}
      //printf("")
      // char restr[1] = "";
      // restr[0] = re;
      strncat(buf,&re,1); //(char *)uart_getc(uart0));
    }
    // sleep_ms(5);
    //sleep_us(100);
    // if(i>10)break;

    // i++;
  }
  // printf("\n");

  // strcat(buf,"\0");
  // return buf;
}

void uart_inp(void){
  //printf("interrupt called");
  if(read_sync){
    read_sync = false;
    char buf[512] = "";
    fetch_Resp(buf,5000);
    if (strlen(buf)>0){
      printf("%s",buf);
      parse_input(buf);

    }
    for (int i=0;i<6;i++){
    printf("%d-",(int32_t)ppm[i]);
    }
    printf("\n");
    read_sync = true;
  }
  
}

void setup_uart_interrupt(){
  read_sync = true;
  printf("interrupt setup");
  irq_set_exclusive_handler(20, uart_inp);
  irq_set_enabled(20, true);
  uart_set_irq_enables(uart0, true, true);
}

void sendCMD_waitResp(const char* cmd,const uint32_t waitTime){
  printf("CMD: %s",cmd);
    
  int sl = strlen(cmd);
  for(int i=0;i<sl;i++)
    uart_putc_raw(uart0, cmd[i]);
  uart_putc_raw(uart0, '\r');
  uart_putc_raw(uart0, '\n');
  // "\r\n");
  //sleep_ms(waitTime);
  // char buf[512] = "";
  // fetch_Resp(buf, waitTime);
  // printf("\n|%s|\n",buf);

  
}
    
void sendMsg(const char* msg){
  char cmd[] = "AT+CIPSEND=";
  int sl = strlen(msg)+2;
  //printf("%d",sl);//
  //printf("%s",msg);//
  char msglen[5];
  itoa(sl, msglen, 10);
  strcat(cmd, msglen);
  for(int i=0;i<sl;i++)
    uart_putc_raw(uart0, cmd[i]);
  printf("%s",cmd);
  uart_putc_raw(uart0, '\r');
  uart_putc_raw(uart0, '\n');
  //uart_puts(uart0, msg);

  int sl1 = strlen(msg);
  for(int i=0;i<sl1;i++)
    uart_putc_raw(uart0, msg[i]);
  uart_putc_raw(uart0, '\r');
  uart_putc_raw(uart0, '\n');
}

int main() {
  // stdio_init_all();
 
  stdio_usb_init();

  uart_init(uart0, 115200);
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
  sleep_ms(5000);    // Give time for the USB to be setup
  // flash(3);       // Time to connect that USB port
  sleep_ms(5000);
  uart_flush(0);


  ppm_init();//ppm
  setup_uart_interrupt();
  printf("out:%d",irq_is_enabled(20));
  sendCMD_waitResp("AT",50000);
  sleep_ms(1000);
//  sendCMD_waitResp("AT+CIFSR",50000);
//  sleep_ms(1000);
  // sendCMD_waitResp("AT+CWJAP=\"jsparrow_2.4Ghz\",\"happy@123\"",50000);
  // sleep_ms(5000);
  // sendCMD_waitResp("AT+CIFSR",50000);
  // sleep_ms(10000);
  sendCMD_waitResp("AT+CIPSTART=\"TCP\",\"192.168.1.5\",9999",500000);
  sleep_ms(10000);
  // sendCMD_waitResp("AT+CIPSEND=7",500000);
  // sleep_ms(10000);
  // sendCMD_waitResp("hello",50000);
  // sleep_ms(3000);

  // setup_uart_interrupt();

  while (true){
    // for(int i =0;i<6;i++){

    //   printf("%d-",ppm[i]);
      
    // }
    // printf("\n");
    // sendCMD_waitResp("AT+",50000);
    // char buf[512] = "";
    // fetch_Resp(buf,50000);
    // if (strlen(buf)>0){
    //   printf("%s",buf);

    sleep_ms(100);
      //printf("%d",strlen(buf));
    // }


    //sleep_ms(50);

  }

  return 0;

}
