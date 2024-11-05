#ifndef TS_LCD 
#define TS_LCD
#include "pico/stdlib.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include <stdint.h>

extern uint32_t savedX;
extern uint32_t savedY;
extern struct TSPoint p;
extern char buffer[30];

//initialisation function
void ts_lcd_init(); 

//status function - returns true when display is touched 
bool get_ts_lcd(uint16_t *pz);

//draw crosshair

//void crosshair(); //CHECKME might need point argument 

#endif