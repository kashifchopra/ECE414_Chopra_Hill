#include "sw_in.h"
#include "pico/stdlib.h"
#include "stdint.h"

void sw_in_init(){
//low level code to initialise port 

const uint32_t MASK_17_16 = 0x00030000; //mask for gpio 17 and 16

gpio_init_mask(MASK_17_16);
gpio_set_dir_in_masked(MASK_17_16);
//will this setup in internal pullups?

gpio_set_pulls(17, 1, 0); //set gpio 17 as pullup 0x00020000
gpio_set_pulls(16, 1, 0); //set gpio 16 as pullup 0x00010000

}

bool sw_in_read1(){
    //low level code to read sw1 at gpio 16
    return !gpio_get(16);
}

bool sw_in_read2(){
    //low level code to read sw2 at gpio 17
return !gpio_get(17);
}