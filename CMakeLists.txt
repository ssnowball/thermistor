cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(thermistor C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(thermistor
	main.c
)

pico_enable_stdio_usb(thermistor 1)
pico_enable_stdio_uart(thermistor 1)

pico_add_extra_outputs(thermistor)

target_link_libraries(thermistor pico_stdlib hardware_adc)
