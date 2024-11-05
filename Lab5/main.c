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


    while(1){
        drawUI();
        ts_lcd_funct(); //this sets the values of savedX and savedY
        input = getInput(savedX, savedY);

        if(get_ts_lcd(&p.z)){
            tckFnct_Calculator();
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

