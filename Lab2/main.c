#include "pico/stdlib.h"
#include "led_out.h"
#include "sw_in.h"
#include "stdint.h"
#include <stdbool.h>  // Explicitly include stdbool.h for bool type

 int main(){

    bool in1,in2; 
    uint16_t out; 

    sw_in_init(); 
    led_out_init(); 

    while(1){
        in1 = sw_in_read1();
        in2 = sw_in_read2();

        if(in1 && in2){
            led_out_write(0xff); //turn on all 8 LEDs 
        } else if(in1 && !in2){
        led_out_write(0x80); //turn on left most LED
        } else if(!in1 && in2){
            led_out_write(0x01); //turn on right most LED
        } else{
            led_out_write(0x00); //turn off all LEDs
        }


}

return 0; 

}