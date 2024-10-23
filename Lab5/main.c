#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include "user_interface.h"
#include "tckFnct_calculator.h"




int main(){
   
   while(1){
     drawUI(); //make the screen
    previnput= input; //save prev input
    //input = updateInput() or whatever function 
    tckFnct_calculator();

   }
   


    /* // Run tests
    testCalculator();

    printf("All tests passed!\n"); */
    return 0;
}

