/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Modified by Ben Hill, Kashif Chopra (08/28/2024)
 */

#include "pico/stdlib.h"
#include "led_out.h"
#include "sw_in.h"
#include "stdint.h"
#include "stdbool.h"


int main() {
    bool in1,in2; 
    uint16_t out; 
    out = 0x99;
    sw_in_init(); 
    led_out_init(); 

    while(1){

        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        sleep_ms(500);
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        sleep_ms(400);

        in1 = sw_in_read1();
        in2 = sw_in_read2();

        /* in1 = 1;
        in2 = 1; */

        if(in1 && in2){
            out = 0xff; //turn on all 8 LEDs 
        } else if(in1 && !in2){
        out = 0x80; //turn on left most LED
        } else if(!in1 && in2){
            out = 0x01; //turn on right most LED
        } else{
            out = 0x00; //turn off all LEDs
        }
        led_out_write(out);


        //testing for blink function:

      
}

return 0; 

}