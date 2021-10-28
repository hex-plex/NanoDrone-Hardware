add_executable(wifi_setup
        main.cpp
        )
# add_executable(FlashTest
#         flash.cpp
# )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(wifi_setup pico_stdlib hardware_gpio hardware_timer pico_multicore hardware_flash)
#add_executable(control_node main.c)
#target_link_libraries(control_node pico_stdlib hardware_gpio hardware_timer pico_multicore)
# target_link_libraries(FlashTest pico_stdlib hardware_gpio hardware_timer pico_multicore hardware_flash hardware_sync)

# enable uart output, disable usb ouput
pico_enable_stdio_uart(wifi_setup 0)
pico_enable_stdio_usb(wifi_setup 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(wifi_setup)


# # enable uart output, disable usb ouput
# pico_enable_stdio_uart(FlashTest 0)
# pico_enable_stdio_usb(FlashTest 1)

# # create map/bin/hex file etc.
# pico_add_extra_outputs(FlashTest)
