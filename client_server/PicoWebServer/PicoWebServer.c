

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"

// #include "hardware/irq.h"
#include <string.h>
// #include <iomanip>
// using namespace std;


//#define WIFISSID "jsparrow_2.4Ghz" // wifi SSID
//#define WIFIPASS "happy@123" // wifi password

#define WIFISSID "JioFiber-QycPA" // wifi SSID
#define WIFIPASS "arunimap" // wifi password
#define STATICIP "192.168.29.161" // static IP for PicoWebServer
#define server_port 80

void fetch_Resp(char* buf, int timeout){
  // char buf[512] = "";
  int64_t prev_time = time_us_64(); 
  while((time_us_64() - prev_time)<timeout*50){
    if(uart_is_readable(uart0)){
      // char re = uart_getc(uart0);
      // char restr[1];
      // restr[0] = re;
      strcat(buf,(char *)uart_getc(uart0));
    }
  }
  // return buf;
}

void sendCMD_waitResp(const char* cmd,int timeout){
  printf("CMD: %s",cmd);
    
  int sl = strlen(cmd);
  for(int i=0;i<sl;i++)
    uart_putc_raw(uart0, cmd[i]);
  uart_putc_raw(uart0, '\r');
  uart_putc_raw(uart0, '\n');
  // "\r\n");
  //sleep_ms(timeout);
  char buf[512] = "";
  fetch_Resp(buf, timeout);
  printf("%s",buf);

  
}
    


int main() {
  // stdio_init_all();
  stdio_usb_init();
  uart_init(uart0, 115200);
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
  sleep_ms(1000);    // Give time for the USB to be setup
  // flash(3);       // Time to connect that USB port
  sleep_ms(2000);

  while(true){
    sendCMD_waitResp("AT",2000);
    printf("Hello\n");
    sleep_ms(100);
  }
  

  // sendCMD_waitResp("AT+CWMODE=3");


  // sendCMD_waitResp("AT+CWLAP",10000);

  // char j[] ="AT+CWJAP=";
  // strcat(j, (char *)WIFISSID);
  // strcat(j, ",");
  // strcat(j, (char *)WIFIPASS);
  // sendCMD_waitResp(j ,5000); //#Connect to AP
  // sendCMD_waitResp("AT+CIFSR");    //#Obtain the Local IP Address
  // sendCMD_waitResp("AT+CIPMUX=0");
  // sendCMD_waitResp("AT+CIPSERVER=1,80");
  // sleep_ms(10000);
  // char k[] ="AT+CIPSTART=\"TCP\",\"";
  // strcat(k, (char *)STATICIP);
  // strcat(k, "\",");
  // strcat(k, (char*)server_port);

  // sendCMD_waitResp(k);
  // while(true){
  //   // printf("enter");
  //   // string inputs; 
  //   // scanf("%s",&inputs);
  //   // string send[]="AT+CIPSEND";
  //   // string size= itos(strlen(inputs));
  //   // strcat(send, ;

  //     printf(fetch_Resp());

  //   // sendCMD_waitResp("AT+CIPSEND");

  // }

  return 0;

}