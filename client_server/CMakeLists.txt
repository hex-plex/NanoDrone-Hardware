cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(client_serv C CXX) # ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# Add subdirectories:
add_subdirectory(PicoWebServer)
