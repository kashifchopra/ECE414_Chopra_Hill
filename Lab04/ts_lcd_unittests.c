#include "pico/stdlib.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <stdio.h>


//initialisation function
void ts_lcd_init(){
    adc_init();
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9340_BLACK);  
}


//status function - returns true when display is touched 
bool get_ts_lcd(uint16_t *px, uint16_t *py){
//TO CHECK: 
if((*px >= 700) && (*px <= 3500) && (*py >= 500) && (*py <= 3500) ) return true; 
return false; 
}



uint64_t interpolateX(uint32_t px){

uint32_t x_lcd = 0; 

x_lcd = (px - 0)*(240-0)/(4096 -0) + 0;

return x_lcd; 

}

uint64_t interpolateY(uint32_t py){

uint32_t y_lcd = 0; 

y_lcd = (py - 0)*(320-0)/(4096 -0) + 0;

return y_lcd; 
}



int main(){

    struct TSPoint p;
                p.x = 0;
                p.y = 0;
                p.z = 0;

    char string[30]; 
    char buffer[30];

    uint64_t savedX;
    uint64_t savedY;
    //initialise LCD touchscreen 
    ts_lcd_init();

        while(1){

        // get input values:

        getPoint(&p);

        //if its touched, then write the location: 
        if(get_ts_lcd(&p.x, &p.y)){ //TOCHECK
        

                //tft_fillScreen(ILI9341_BLACK);
                tft_setCursor(20, 100);
                tft_setTextColor(ILI9340_WHITE); tft_setTextSize(2);

                //erase old text
                tft_setTextColor(ILI9340_BLACK);
                tft_writeString(buffer);
                
                
                //getPoint(&p);
                tft_setCursor(20, 100);
                tft_setTextColor(ILI9340_WHITE);
                sprintf(buffer,"x: %d, y: %d", interpolateX(p.x), interpolateY(p.y));
                tft_writeString(buffer);
            
                //save most recent coordinates as whole string (could have saved p.x, p.y etc individually too)
                //string = buffer; 
                savedX = interpolateX(p.x);
                savedY = interpolateX(p.y);

                sleep_ms(100);
            
        } else{
            //print the old values 
            tft_setCursor(20,100);
            tft_setTextColor(ILI9340_WHITE);
            sprintf(string,"x: %d, y: %d",savedX,savedY); //TOCHECK
            tft_writeString(string);

            //print the old cursor 
        }
        
        }

        return 1; 
 
}

    