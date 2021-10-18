

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

#define WIFISSID "No" // wifi SSID
#define WIFIPASS "abcdq1987654" // wifi password
#define STATICIP "192.168.43.18" // static IP for PicoWebServer
#define server_port 9999


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

void fetch_Resp(char* buf, const uint32_t waitTime){
  // char buf[512] = "";
  printf("%d\n", waitTime);
  int64_t prev_time = time_us_64(); 
  //uint32_t i=0;
  while((int64_t)(time_us_64() - prev_time) < (int64_t)(waitTime)){
    printf("%ld, %d |", (long)(time_us_64()-prev_time), waitTime);
   
    if(uart_is_readable(uart0)){
      char re = uart_getc(uart0);
      char restr[1];
      restr[0] = re;
      strcat(buf,restr); //(char *)uart_getc(uart0));
     
    }
    sleep_us(30);
    // if(i>10)break;

    // i++;
  }
  strcat(buf,"\0");
  // return buf;
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
  char buf[512] = "";
  fetch_Resp(buf, waitTime);
  printf("%s",buf);

  
}
    
void sendMsg(const char* msg){
  char cmd[] = "AT+CIPSEND=";
  int sl = strlen(msg);
  char msglen[5];
  itoa(sl, msglen, 10);
  strcat(cmd, msglen);
  for(int i=0;i<sl;i++)
    uart_putc_raw(uart0, cmd[i]);
  uart_putc_raw(uart0, '\r');
  uart_putc_raw(uart0, '\n');
  uart_puts(uart0, msg);
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


  sendCMD_waitResp("AT",20000);
  sleep_ms(1000);
  sendCMD_waitResp("AT+CIFSR",20000);
  sleep_ms(1000);
  sendCMD_waitResp("AT+CIFSR",20000);
  sleep_ms(1000);
  sendCMD_waitResp("AT+CIPSTART=\"TCP\",\"192.168.43.18\",9999",20000);
  sleep_ms(500);
  sendMsg("");

  while(true){
  //  printf("Hello\n");
    // sendCMD_waitResp("AT",2000);
    
    // sleep_ms(1000);
    char msg[10] = "";
    printf("enter your message");
    scanf("%s", msg);
    sendCMD_waitResp("AT+CIPSTART=\"TCP\",\"192.168.43.18\",9999",20000);
    sendMsg("");
    sendMsg(msg);
  }
  
  return 0;

}