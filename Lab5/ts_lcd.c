#include "pico/stdlib.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <stdio.h>

//from the old main function in ts_lcd from lab4 

uint32_t savedX;
uint32_t savedY;
struct TSPoint p;  // Declare without initialization


char buffer[30];



//initialisation function
void ts_lcd_init(){
    adc_init();
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9340_BLACK);
    p.x = 0;
    p.y = 0;
    p.z = 0;  
    tft_fillRect(10, 10, 50, 50, ILI9340_RED);//test

     sleep_ms(100);
}


//status function - returns true when display is touched 
bool get_ts_lcd(uint16_t *pz){
//TO CHECK: 
if (*pz < 1000) return true; 
return false; 
}



uint32_t interpolateX(uint16_t px){ //long side for us

uint32_t x_lcd = 0; 

x_lcd = (px - 0)*(320-0)/(4096 -0) + 0; //changed from 4096 to 8000

return (320 - x_lcd); //x given by getPoint is in opposite to our orientation

}

uint32_t interpolateY(uint16_t py){  // short side for us

uint32_t y_lcd = 0; 

y_lcd = (py - 0)*(240-0)/(2730 -0) - 65; // -65 to calibrate it to get it at exact 0

return (y_lcd); // values were switched in the getPpint function cos that assumes a different screen rotation and axes
}



void ts_lcd_funct(){

                
        // get input values:

        getPoint(&p);
        

        //if its touched, then write the location: 
        if(get_ts_lcd(&p.z)){ //TOCHECK
        

                
               /*  tft_setCursor(100, 200);
                tft_setTextColor(ILI9340_WHITE); tft_setTextSize(2);

                //erase old text
                tft_setTextColor(ILI9340_BLACK);
                tft_writeString(buffer); */
                
                
                //getPoint(&p);
               // tft_setCursor(100, 200);
               // tft_setTextColor(ILI9340_WHITE);
                //sprintf(buffer,"x: %d, y: %d", interpolateX(p.y), interpolateY(p.x)); 
                //tft_writeString(buffer); 
               //tft_writeString("TOUCHED"); 
            
                //save most recent coordinates as whole string (could have saved p.x, p.y etc individually too)
                //string = buffer; 
                savedY = interpolateY(p.x);
                savedX = interpolateX(p.y);

                sleep_ms(100);
            
        } else{
            //print the old values - comment out 
           // tft_setCursor(100,200);
            //tft_setTextColor(ILI9340_WHITE);
           // sprintf(buffer,"x: %d, y: %d", savedX, savedY); //TOCHECK
          //  tft_writeString(buffer);

            //print the old cursor 
        }

       // tft_drawFastHLine(savedX-5, savedY, 10, ILI9340_RED);
       // tft_drawFastVLine(savedX, savedY-5, 10, ILI9340_RED);
 
}
