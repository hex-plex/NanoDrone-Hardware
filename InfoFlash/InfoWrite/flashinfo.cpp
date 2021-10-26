#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdio.h"
#include "pico/stdlib.h"

#include "flash_utils.h"

 
int main() {
    // stdio_init_all();

    stdio_usb_init();
    
    sleep_ms(1000);

    // while(true){
        
    //     printf("hell");
    //     sleep_ms(10);
    // }
    
    
    writeCreds();

    sleep_ms(1000);
    return 0;
}