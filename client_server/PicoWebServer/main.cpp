

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#include "hardware/timer.h"

#include "pico/multicore.h"
#include <string.h>
#include "flash_utils.h"
#include "espUart.h"
#include "hardware/gpio.h"




int main() {
  stdio_init_all();
  stdio_usb_init();

  sleep_ms(5000);

  // writeCreds();
  
  fetchCreds();

  ppm_init();

  uart_init(uart0, 115200);
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
  sleep_ms(5000);
  sleep_ms(5000);
  uart_flush(0);

  

  

  setup_uart_interrupt();
  

  sendCMD_waitResp("AT",50000);
  sleep_ms(1000);
  

  char inp_str[MAX_LEN] = "AT+CIPSTART=\"TCP\",\"";
  strcat(inp_str, cred_.server_ip);
  strncat(inp_str, "\",",2);
  strcat(inp_str, cred_.port);
  printf("%s",inp_str);

  
  sendCMD_waitResp(inp_str,50000);
  printf("\nLoopStarts\n");

  // gpio_init(LED_PIN);
  // gpio_set_dir(LED_PIN, GPIO_OUT);
  while(true){
    sleep_ms(10000);
  }
  

  // sendCMD_waitResp("AT+CIPSTART=\"TCP\",\"192.168.1.5\",9999",500000);
  // sleep_ms(10000);

  // while (true){
  //   gpio_put(LED_PIN, 0);
  //   sleep_ms(500);
  //   gpio_put(LED_PIN, 1);
  //   sleep_ms(500);
  // }

  return 0;

}
