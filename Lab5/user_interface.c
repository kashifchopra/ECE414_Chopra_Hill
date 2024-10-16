#include <stdio.h>         //The standard C library
#include <math.h>          //The standard math library
#include "pico/stdlib.h"   //Standard library for Pico
#include "pico/rand.h"     // for random numbers
#include "TFTMaster.h"     //The TFT Master library

void drawUI(){

    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9340_BLACK);  
    tft_setTextSize(2);

    //RECT COORDINATES: 
        //   10       85      160     245
        //40


        //90


        //140


        //190
    




}

