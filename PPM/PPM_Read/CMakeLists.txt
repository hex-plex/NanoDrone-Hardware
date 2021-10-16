add_executable(PPM_Read
        PPM_Read.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(PPM_Read pico_stdlib hardware_gpio hardware_timer)

# enable usb output, disable uart ouput
pico_enable_stdio_uart(PPM_Read 0)
pico_enable_stdio_usb(PPM_Read 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(PPM_Read)

