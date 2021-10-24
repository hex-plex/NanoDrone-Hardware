add_executable(PicoESP
        PicoWebServer.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(PicoESP pico_stdlib hardware_gpio hardware_timer)
#add_executable(control_node main.c)
#target_link_libraries(control_node pico_stdlib hardware_gpio hardware_timer pico_multicore)

# enable uart output, disable usb ouput
pico_enable_stdio_uart(PicoESP 0)
pico_enable_stdio_usb(PicoESP 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(PicoESP)

