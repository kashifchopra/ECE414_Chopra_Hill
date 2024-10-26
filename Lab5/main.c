#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include "user_interface.h"
#include "tckFnct_calculator.h"
#include "touchNum.h"
#include "ts_lcd.h"




int main(){
   drawUI();
   int input;
   int x;
   int y;
   static int cursorX = 5;

    struct TSPoint tp;
            tp.x = 0;
            tp.y = 0;
            tp.z = 0;
    
    input = getInput(x, y);

   while(1){
     
     if(get_ts_lcd(tp.x, tp.y)){
      
      tft_setCursor(cursorX, 5);
      tft_drawCircle(100,100,65,ILI9340_WHITE);

     }

    // previnput= input; //save prev input
    // //input = updateInput() or whatever function 
    // tckFnct_calculator();

   }
   


    /* // Run tests
    testCalculator();

    printf("All tests passed!\n"); */
    return 0;
}

