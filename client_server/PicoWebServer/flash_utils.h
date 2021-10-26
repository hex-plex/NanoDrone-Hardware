#include <stdio.h>
#include <stdlib.h>
 
#include "pico/stdlib.h"
#include "hardware/flash.h"
#include "hardware/sync.h"

#ifndef __FLSH_TOOL__
#define __FLSH_TOOL__

#define FLASH_TARGET_OFFSET (1024 * 1024)
#define FLASH_SECTOR_SIZE 40 * 4096 
#define MAX_LEN 200

const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);

struct cred{
    char wifi_name[MAX_LEN];
    char pass[MAX_LEN];
    char server_ip[MAX_LEN];
    char port[MAX_LEN];


} cred_;


void fetchCreds(){
    int cnt = 0;
    strcpy(cred_.wifi_name, "");
    strcpy(cred_.pass, "");
    strcpy(cred_.server_ip, "");
    strcpy(cred_.port, "");
    
    printf("Fetching info");
    for(size_t i=0; i < (size_t)FLASH_PAGE_SIZE; i++){
        if((char)flash_target_contents[i] == '|'){
            if(cnt==0){
                strncat(cred_.wifi_name, "\0", 1);
            } else if (cnt==1) {
                strncat(cred_.pass, "\0", 1);
            } else if (cnt==2) {
                strncat(cred_.server_ip, "\0", 1);
            } else if (cnt==3) {
                strncat(cred_.port, "\0", 1);
            }
            cnt++;
            if(cnt>=4)break;
            continue;
        }
        
        printf("%c", flash_target_contents[i]);

        if(cnt==0){
            strncat(cred_.wifi_name, (const char *)flash_target_contents+i, 1);
        } else if (cnt==1) {
            strncat(cred_.pass, (const char *)flash_target_contents+i, 1);
        } else if (cnt==2) {
            strncat(cred_.server_ip, (const char *)flash_target_contents+i, 1);
        } else if (cnt==3) {
            strncat(cred_.port, (const char *)flash_target_contents+i, 1);
        }
    }
    printf("Info Fetched");
}
 
void writeCreds(){
    flash_range_erase(FLASH_TARGET_OFFSET, FLASH_SECTOR_SIZE);
    // strcpy(cred_.wifi_name, "");
    // strcpy(cred_.pass, "");
    // strcpy(cred_.server_ip, "");
    // strcpy(cred_.port, "");
    char info_set[FLASH_PAGE_SIZE];
    strcpy(info_set, ""); 
    printf("Input WifiName, Password, Server IP, Port each in a new line\n");
    char temp_buf[MAX_LEN];
    int cnt=0;   
    for(int i=0;i<4;i++){
        scanf("%s",temp_buf);
        if(cnt==0){
            strcat(info_set, temp_buf);
            strncat(info_set, "|", 1);
            strcpy(cred_.wifi_name,temp_buf);
        } else if (cnt==1){
            strcat(info_set, temp_buf);
            strncat(info_set, "|", 1);
            strcpy(cred_.pass, temp_buf);
        } else if (cnt==2){
            strcat(info_set, temp_buf);
            strncat(info_set, "|", 1);
            strcpy(cred_.server_ip, temp_buf);
        } else if (cnt==3){
            strcat(info_set, temp_buf);
            strncat(info_set, "|", 1);
            strcpy(cred_.port, temp_buf);
        }
    }
    flash_range_program(FLASH_TARGET_OFFSET, (uint8_t *)info_set , FLASH_PAGE_SIZE);
}

 
// int main() {
//     stdio_usb_init();
//     uint8_t random_data[FLASH_PAGE_SIZE];
//     for (int i = 0; i < FLASH_PAGE_SIZE; ++i)
//         random_data[i] = rand() >> 16;
 
//     printf("Generated random data:\n");
//     print_buf(random_data, FLASH_PAGE_SIZE);
    
 
//     // Note that a whole number of sectors must be erased at a time.
//     printf("\nErasing target region...\n");
//     // uint32_t ints = save_and_disable_interrupts();
//     flash_range_erase(FLASH_TARGET_OFFSET, FLASH_SECTOR_SIZE);
//     // restore_interrupts(ints);

//     printf("Done. Read back target region:\n");
//     print_buf(flash_target_contents, FLASH_PAGE_SIZE);
    
//     printf("\nProgramming target region...\n");
//     flash_range_program(FLASH_TARGET_OFFSET, random_data, FLASH_PAGE_SIZE);
//     printf("Done. Read back target region:\n");
//     print_buf(flash_target_contents, FLASH_PAGE_SIZE);
 
//     bool mismatch = false;
//     for (int i = 0; i < FLASH_PAGE_SIZE; ++i) {
//         if (random_data[i] != flash_target_contents[i])
//             mismatch = true;
//     }
//     if (mismatch)
//         printf("Programming failed!\n");
//     else
//         printf("Programming successful!\n");
// }

#endif