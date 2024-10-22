/*
* Author: Kashif Chopra
* Date: 10/18/24
*/


#include "TFTMaster.h"
#include "pico/stdlib.h"

//first define states - 
//initial, num1, op, num2, result, error, (maybe div0 too)
static enum CALC_STATES{
initial,num1,num1neg, op,num2,result,error, div0 //maybe keep/remove div0state
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
        if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
            CALC_STATE = num1;
        }else if(input>=10 && input <=13 ){
            CALC_STATE = op;
        } else if(input == 14){
            CALC_STATE = result;
        } else if(input == 15){
            CALC_STATE = initial; 
        }
        break;

    case op: 
        if(0<=input && input<=9){ 
            CALC_STATE = num2;
        }else if(input>=10 || input ==12 || input <=13 ){
            CALC_STATE = error;
        else if(input == 11){
            CALC_STATE = num2;
        }
        } else if(input == 14){
            CALC_STATE = result;
        } else if(input == 15){
            CALC_STATE = initial; 
        }
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