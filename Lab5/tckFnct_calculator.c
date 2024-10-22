/*
* Author: Kashif Chopra
* Date: 10/18/24
*/


#include "TFTMaster.h"
#include "pico/stdlib.h"

//first define states - 
//initial, num1, op, num2, result, error, (maybe div0 too)
static enum CALC_STATES{
initial,num1,op,num2,result,error, div0 //maybe keep/remove div0state
} CALC_STATE;

//global variables
static uint32_t input;


void tckFnct_Calculator(){

//define variables/flags 

//define state change scenarios with switch case
switch(CALC_STATE){

    case initial: 
        
        //if input = any num 0-9, next state = num1
        
        if(0<=input && input<=9){
            CALC_STATE = num1;
            break;
        } else if (input == 10 || input == 11)  // for +ve or -ve number sign 
        {
            CALC_STATE = op;
        } else{
            CALC_STATE = initial;
        }
        break;

    case num1: 

        break;

    case op: 

        break;

    case num2: 

        break;

    case result: 

        break;

    case error: 

        break;

    case div0: 

        break;

    default:
        CALC_STATE = initial; 
        break; 
}

//define actions within each state with switch case 


}