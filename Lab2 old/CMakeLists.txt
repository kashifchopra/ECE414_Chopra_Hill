cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH "C:/Users/choprak/Documents/pico/pico-sdk")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(Lab2)

pico_sdk_init()

add_executable(Lab2
        led_out.c
	led_out.h
	sw_in.c
	sw_in.h
	main.c
        )

# pull in common dependencies
target_link_libraries(Lab2 pico_stdlib pico_bootsel_via_double_reset)

# create map/bin/hex file etc.
pico_add_extra_outputs(Lab2)

