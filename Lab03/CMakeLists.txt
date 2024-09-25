cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(Lab03)

pico_sdk_init()

add_executable(Lab03
        fsm.c
        led_out.h
        led_out.c
        sw_in.c
        sw_in.h
	debounce_sw2.c
	debounce_sw2.h
	debounce_sw1.c
	debounce_sw1.h
	timer.c
	timer.h
        )

# pull in common dependencies
target_link_libraries(Lab03 pico_stdlib pico_bootsel_via_double_reset)

# create map/bin/hex file etc.
pico_add_extra_outputs(Lab03)

