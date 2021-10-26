cmake_minimum_required(VERSION 3.12)
set(PICO_COPY_TO_RAM 1)   ## fixes most of the bugs

include(pico_sdk_import.cmake)

project(dynamic_info C CXX) # ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# Add subdirectories:
add_subdirectory(InfoWrite)
