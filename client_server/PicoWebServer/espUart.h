#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "ppm.h"

#ifndef __ESP_UART__
#define __ESP_UART__


bool read_sync;

// #define FLASH_TARGET_OFFSET (1024 * 1024)
// #define FLASH_SECTOR_SIZE 40 * 4096
// const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);


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
  if(true || read_sync){
    read_sync = false;
    char buf[512] = "";
    fetch_Resp(buf,5000);
    if (strlen(buf)>0){
      if(DEBUG_PRINT) printf("%s",buf);
      parse_input(buf);

    }
    if(DEBUG_PRINT){
      for (int i=0;i<6;i++){
        printf("%d-",(int32_t)ppm[i]);
      }
      printf("\n");
    }
    
    read_sync = true;
  }
  
}

void setup_uart_interrupt(){
  read_sync = true;
  printf("interrupt setup");
  irq_set_exclusive_handler(20, uart_inp);
  irq_set_enabled(20, true);
  uart_set_irq_enables(uart0, true, false);
  printf("%d",irq_is_enabled(20));
}

void sendCMD_waitResp(const char* cmd,const uint32_t waitTime){
  if(DEBUG_PRINT)printf("CMD: %s",cmd);
    
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
  if(DEBUG_PRINT)printf("%s",cmd);
  uart_putc_raw(uart0, '\r');
  uart_putc_raw(uart0, '\n');
  //uart_puts(uart0, msg);

  int sl1 = strlen(msg);
  for(int i=0;i<sl1;i++)
    uart_putc_raw(uart0, msg[i]);
  uart_putc_raw(uart0, '\r');
  uart_putc_raw(uart0, '\n');
}

#endif