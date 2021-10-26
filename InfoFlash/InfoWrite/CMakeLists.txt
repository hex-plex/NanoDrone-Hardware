add_executable(FlashWrite
        flashinfo.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(FlashWrite pico_stdlib hardware_timer hardware_flash)
#add_executable(control_node main.c)
#target_link_libraries(control_node pico_stdlib hardware_gpio hardware_timer pico_multicore)
# target_link_libraries(FlashWrite pico_stdlib hardware_gpio hardware_timer pico_multicore hardware_flash hardware_sync)

# enable uart output, disable usb ouput
pico_enable_stdio_uart(FlashWrite 0)
pico_enable_stdio_usb(FlashWrite 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(FlashWrite)