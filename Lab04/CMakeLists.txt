cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ts_lcd)

pico_sdk_init()

add_executable(ts_lcd)

pico_generate_pio_header(ts_lcd ${CMAKE_CURRENT_LIST_DIR}/SPIPIO.pio)

target_sources(ts_lcd PRIVATE 
    ts_lcd.c
    TouchScreen.c
    TFTMaster.c
    glcdfont.c
    
    )

target_link_libraries(ts_lcd PRIVATE 
    pico_stdlib 
    hardware_adc 
    hardware_gpio hardware_pio 
    hardware_irq    
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(ts_lcd)






