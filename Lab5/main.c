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

   ts_lcd_init(); 
   drawUI();

    while(1){
        
        if(get_ts_lcd(&p.z)){ //if touch detected
            
            
                ts_lcd_funct(); //sets values of savedX and SavedY
                // uint32_t val = getInput(savedX, savedY); //gets input value
                // processInp(val); //runs calc

            // tckFnct_Calculator();
            /* if(stateVar=="result"){
                screenOut = res;
            } else{ //add errFlag and zeroErr case here too later
                screenOut = input;
            } */
        }
    }

    // previnput= input; //save prev input
    // //input = updateInput() or whatever function 
    // tckFnct_calculator();
    return 0;
}

