#ifndef TS_LCD 
#define TS_LCD
#include "pico/stdlib.h"
#include "TouchScreen.h"
#include "TFTMaster.h"

//initialisation function
void ts_lcd_init(); 

//status function - returns true when display is touched 
bool get_ts_lcd(uint16_t *px, uint16_t *py);

//draw crosshair

//void crosshair(); //CHECKME might need point argument 

#endif