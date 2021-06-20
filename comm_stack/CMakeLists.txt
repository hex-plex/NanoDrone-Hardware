cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(comm_stack C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

include_directories(
    include/
)

# Include your header here
# set(PPM_SIG include/${PROJECT_NAME}/)

add_subdirectory(ppm_gen)

add_compile_option(-Wall
	-Wno-format
	-Wno-unused-function
	-Wno-maybe-uninitialized
	)
