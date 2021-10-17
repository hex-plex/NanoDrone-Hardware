add_executable(PPM_Generate
        PPM_Generate.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(PPM_Generate pico_stdlib hardware_gpio hardware_timer)
#add_executable(control_node main.c)
#target_link_libraries(control_node pico_stdlib hardware_gpio hardware_timer)

# enable uart output, disable usb ouput
pico_enable_stdio_uart(PPM_Generate 0)
pico_enable_stdio_usb(PPM_Generate 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(PPM_Generate)

