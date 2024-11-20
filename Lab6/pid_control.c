/*
* Author: Kashif Chopra
* Date: 11/20/24
*/

#include "pico/stdlib.h"
#include <stdio.h>

//defining states 

static enum STATES{
    init, ctrl
}STATE


//global variables 
int32_t actual_speed; // 
int32_t desired_speed; //
int32_t actual_prev; //
int32_t error; //Desired RPM - Actual RPM 
int8_t actuator; //actuator value //float? 
int32_t deriv; //or should this be float? 12.4 float? 
int32_t integ; //CHECK might be float 
int32_t integMax; //CHECK might be float 
int32_t integMax; //CHECK might be float 
const signed char Kp = 5; //ADJUST this after testing!!!
const signed char Ki = 5; //ADJUST this after testing!!! Typically Ki<<Kp 
const signed char Kd = 5; //ADJUST this after testing!!! Typically Kd>Kp 


//helper functions

void init(){
    actuator = 0; 
    deriv = 0; 
    integ = 0; 
    integMax = 0; 
    //add more as needed
    actual_prev = 0; 
    error = 0; // check these if all are needed 
}

void calc_integ(){ //CHECK LATER
integ = integ + error; 
if(integ>integMax){
    integ = integMax;
} else if (integ<integMin){
    integ = integMin; 
}
}


//FSM: 


void pid_control_fsm(){
   
   //state transitions 
    switch (STATE)
    {
    case init:
        STATE = ctrl; 
        break;

    case ctrl: 
        STATE = ctrl; 
        break; 

    default:
        STATE = init;   
        break;
    }

    switch (STATE)
    {
    case init:
        init(); 
        break;

    case ctrl: 
      //set error, deriv, and integ 
        error = desired_speed - actual_speed;  
        deriv = actual_speed - actual_prev;
        calc_integ(); 

        //adjust actuator 
        actuator = Kp*error + Ki*integ + Kd*deriv 
        //if actuator (8 bit) value > 255, actuator = 255. If -ve, saturate at 0.  
        if(actuator>255){
            actuator = 255;
        }

        if(actuator < 0){
            actuatpr = 0; 
        }


        break; 

    default:
       // 
        break;
    }

    //state actions 
        //init state 
        //init(); 

        //control state 
        

}
