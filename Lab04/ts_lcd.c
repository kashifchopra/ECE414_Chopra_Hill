#include "pico/stdlib.h"
#include "TouchScreen.h"
#include "TFTMaster.h"


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
bool get_ts_lcd(unit16_t *px, unit16_t *py){
//TO CHECK: 
if((*px >= 700) && (*px <= 3500) && (*py >= 500) && (*py <= 3500) ) return true; 
return false; 
}



int main(){


struct TSPoint p;
            p.x = 0;
            p.y = 0;
            p.z = 0;

//initialise LCD touchscreen 
ts_lcd_init();

    while(1){

    // get input values:

    getPoint(&p);

    char buffer[]; 

    //if its touched, then write the location: 
    if(get_ts_lcd(p.x, p.y)){ //TOCHECK
       
            //tft_fillScreen(ILI9341_BLACK);
            tft_setCursor(20, 100);
            tft_setTextColor(ILI9340_WHITE); tft_setTextSize(2);

            //erase old text
            tft_setTextColor(ILI9340_BLACK);
            tft_writeString(buffer);
            
            
            getPoint(&p);
            tft_setCursor(20, 100);
            tft_setTextColor(ILI9340_WHITE);
            sprintf(buffer,"x: %d, y: %d, z: %d", p.x, p.y, p.z);
            tft_writeString(buffer);
        
            //save most recent coordinates as whole string (could have saved p.x, p.y etc individually too)
            buffer[] = buffer; 

            sleep_ms(100);
        
    } else{
        //print the old values 
        tft_setCursor(20,100);
        tft_setTextColor(ILI9340_WHITE);
        sprintf(buffer);
        tft_writeString(buffer);

        //print the old cursor 
    }
    
    }
 
}

    