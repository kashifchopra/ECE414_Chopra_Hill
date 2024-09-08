#include "led_out.h"
#include "pico/stdlib.h"
#include <stdint.h>

const uint32_t MASK_9_2 = 0x000003fc;
void led_out_init(){


// Initalise the GPIO pins 2 through 9 as output pins
/* for(int i = 2; i<10; i++){ //Q: would this have worked? 
gpio_init(i);
gpio_set_dir(i, 1); //set each as an output pin - 1 is for out and 0 is for input 
} */

gpio_init_mask(MASK_9_2);
gpio_set_dir_out_masked(MASK_9_2); 

}


void led_out_write(uint8_t val){
    gpio_put_masked(MASK_9_2, val<<2); //writrs the val value to gpio 9 through 2. Need to shift by 2 to align it with bits 9 through 2. 
}