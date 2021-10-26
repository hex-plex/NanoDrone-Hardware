

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#include "hardware/timer.h"

#include "pico/multicore.h"
#include <string.h>
#include "flash_utils.h"
#include "espUart.h"




//#define WIFISSID "jsparrow_2.4Ghz" // wifi SSID
//#define WIFIPASS "happy@123" // wifi password

#define WIFISSID "No" // wifi SSID
#define WIFIPASS "abcdq1987654" // wifi password
#define STATICIP "192.168.1.5" // static IP for PicoWebServer
#define server_port 9999


void print_buf(const uint8_t *buf, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02x", buf[i]);
        if (i % 16 == 15)
            printf("\n");
        else
            printf(" ");
    }
}


int main() {
 
  stdio_usb_init();

  sleep_ms(5000);

  fetchCreds();
 

  uart_init(uart0, 115200);
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
  sleep_ms(5000);
  sleep_ms(5000);
  uart_flush(0);


  ppm_init();
  setup_uart_interrupt();
  
  sendCMD_waitResp("AT",50000);
  sleep_ms(1000);
  
  //sendCMD_waitResp("AT+CIFSR",50000);
  //sleep_ms(1000);
  // sendCMD_waitResp("AT+CWJAP=\"jsparrow_2.4Ghz\",\"happy@123\"",50000);
  // sleep_ms(5000);
  // sendCMD_waitResp("AT+CIFSR",50000);
  // sleep_ms(10000);
  

  char inp_str[] = "AT+CIPSTART=\"TCP\",\"";
  strcat(inp_str, cred_.server_ip);
  strncat(inp_str, "\",",2);
  strcat(inp_str, cred_.port);

  // sendCMD_waitResp(inp_str,500000);
  

  sendCMD_waitResp("AT+CIPSTART=\"TCP\",\"192.168.1.5\",9999",500000);
  sleep_ms(10000);

  while (true){
    sleep_ms(100);
  }

  return 0;

}
