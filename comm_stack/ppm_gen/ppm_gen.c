/**
 * ppm_gen.c
 *
 * Author  : Somnath Sendhil Kumar
 * Created : 20 June 2020
*/

#include <stdio.h>
#include <pico/stdlib.h>

int main(){
    stdio_init_all();
    while (true) {
        printf("Hello, world!\n");
        sleep_ms();
    }
    return 0;
}
