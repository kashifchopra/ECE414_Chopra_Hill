#include "pico/stdlib.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "stdio.h"
#include "stdbool.h"
#include <stdio.h>


//initialisation function
void ts_lcd_init(){
    
}


//status function - returns true when display is touched 
bool get_ts_lcd(uint16_t *px, uint16_t *py){
    struct TSPoint tp;

    getPoint(& tp);

    int x;
    int y;
    x = ((320)*(tp.y - 3100))/(400-3100);
    y = ((240)*(tp.x - 790))/(4150-710);
    *px = x;
    *py = y;

    //TO CHECK: 
    if (tp.z < 400){
        return true; 
    } else if (tp.z > 400){
        return false; 
    }



uint32_t interpolateX(uint16_t px){ //long side for us

uint32_t x_lcd = 0; 

x_lcd = (px - 0)*(320-0)/(4096 -0); //changed from 4096 to 8000

return (320 - x_lcd); //x given by getPoint is in opposite to our orientation

}

uint32_t interpolateY(uint16_t py){  // short side for us

uint32_t y_lcd = 0; 

y_lcd = (py - 0)*(240-0)/(2730 -0) - 65; // -65 to calibrate it to get it at exact 0

return (y_lcd); // values were switched in the getPpint function cos that assumes a different screen rotation and axes
}
}


    