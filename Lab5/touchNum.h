//module to return an integer value to FSM for button press based on position of the touchscreen touched. 
#ifndef TOUCHNUM
#define TOUCHNUM
#include "ts_lcd.h"
#include "tckFnct_calculator.h"
#include "hardware/gpio.h"
#include "TFTMaster.h"
#include <stdio.h>
#include "pico/stdlib.h"

//int input();
int getInput(int x, int y);

#endif

