// #ifndef USER_INTERFACE
// #define USER_INTERFACE

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "TouchScreen.h"
#include "TFTMaster.h"

extern char screenOut[30];

void drawUI();