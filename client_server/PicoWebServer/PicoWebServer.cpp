

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "ppm.h"
#include "hardware/irq.h"
#include <string.h>
// #include <iomanip>
// using namespace std;


//#define WIFISSID "jsparrow_2.4Ghz" // wifi SSID
//#define WIFIPASS "happy@123" // wifi password

#define WIFISSID "No" // wifi SSID
#define WIFIPASS "abcdq1987654" // wifi password
#define STATICIP "192.168.43.18" // static IP for PicoWebServer
#define server_port 9999

PPMGen ppmObj;

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

void parse_input(char* buf, PPMGen& obj){
  buf;
  int i=0, cnt = 0;
  int n = strlen(buf);
  while(i<n){
    if(buf[i]=='$')
    {
      i++;
      break;
    }
    i++;
  }
  int val = 0;
  for(;i<n;i++){
    if(buf[i]=='%')break;
    if(buf[i]==',')
    {
      ppm[cnt] = val;
      val = 0;
      cnt++;
    } else {
      val*=10;
      val += (int)(buf[i]-'0');
    }
  }
}



void fetch_Resp(char* buf, const uint32_t waitTime){
  // char buf[512] = "";
  //printf("%d\n", waitTime);
  int64_t prev_time = time_us_64();
  //uint32_t i=0;
  while((int64_t)(time_us_64() - prev_time) < (int64_t)(waitTime)){
    printf("%ld, %d |", (long)(time_us_64()-prev_time), waitTime);
   
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

void uart0_irq(void){
  printf("interrupt called");
  char buf[512] = "";
  fetch_Resp(buf,5000);
  if (strlen(buf)>0){
    printf("%s",buf);
    parse_input(buf, ppmObj);
  }
}

void setup_uart_interrupt(){
  printf("interrupt setup");
  // irq_set_exclusive_handler(20, uart_inp);
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
  printf("%d",sl);//
  printf("%s",msg);//
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

  setup_uart_interrupt();
  printf("out:%d",irq_is_enabled(20));
  sendCMD_waitResp("AT",50000);
  sleep_ms(1000);
//  sendCMD_waitResp("AT+CIFSR",50000);
//  sleep_ms(1000);
  // sendCMD_waitResp("AT+CWJAP=\"jsparrow_2.4Ghz\",\"happy@123\"",50000);
  // sleep_ms(5000);
  sendCMD_waitResp("AT+CIFSR",50000);
  sleep_ms(1000);
  sendCMD_waitResp("AT+CIPSTART=\"TCP\",\"192.168.43.18\",9999",500000);
  sleep_ms(10000);
  sendCMD_waitResp("AT+CIPSEND=7",500000);
  sleep_ms(10000);
  sendCMD_waitResp("hello",50000);
  sleep_ms(3000);

  // setup_uart_interrupt();

  while (true){
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
  //sendMsg("");

  // while(true){
  // //  printf("Hello\n");
  //   // sendCMD_waitResp("AT",2000);
    
  //   // sleep_ms(1000);
  //   char msg[10] = "";
  //   printf("enter your message");
  //   scanf("%s", msg);
  //   sendCMD_waitResp("AT+CIPSTART=\"TCP\",\"192.168.1.4\",9999",50000);
  //   //sendMsg("");
  //   sendMsg(msg);
  //   sleep_ms(1000);
  //   sendCMD_waitResp("AT+CIPCLOSE",50000);
  //   sleep_ms(1000);
  // }
  
  return 0;

}
