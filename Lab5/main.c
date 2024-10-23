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
   
   int input;
   int x;
   int y;
   static int cursorX = 5;

    struct TSPoint p;
            p.x = 0;
            p.y = 0;
            p.z = 0;
    
    input = getInput(x, y);

   while(1){
     drawUI(); //make the screen
     //TEST FUNCTION FOR BUTTON ACCURACY
      if(get_ts_lcd()){
            getPoint(&p);
            x = p.x;
            y = p.y;
            input = getInput(x, y);

          tft_setCursor(cursorX, 5);
          tft_writeString(input);
          cursorX = cursorX + 5;
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

