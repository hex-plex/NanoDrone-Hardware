
cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()
add_executable(PicoWebServer PicoWebServer.cpp) 

target_link_libraries(PicoWebServer pico_stdlib )
pico_enable_stdio_usb(PicoWebServer 1)
pico_enable_stdio_uart(PicoWebServer 0)
pico_add_extra_outputs(PicoWebServer)

