#include "pico/stdlib.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "sw_in.h"
#include "led_out.h"
#include "timer.h"
#include "debounce_sw1.h"
#include "debounce_sw2.h"

static enum STATE{
    INITIAL,
    SERVE1,
    SERVE2,
    L1,
    L2,
    L3,
    L4,
    L5,
    L6,
    L7,
    L8, 
    WIN1,
    WIN2
} STATE;

//set std game period 
unint32_t GAMEPERIOD = 300;

void TickFct_Pong(){
    bool btn1_pressed;
    bool btn2_pressed;

    static bool serve1;
    static bool right; //directional boolean
    static bool winner; //boolean for accounting which side will be wiinner mid play. If 1 -> left wins. 

switch(STATE){

case INITIAL:
    STATE = SERVE1;
    serve1 = true;
    break;

case SERVE1:
    if(btn1_pressed){
        STATE = L1;
    } else if(!serve1 && !btn1_pressed){
        STATE = SERVE1; //latch
    } else if(!serve1 && btn1_pressed){
        STATE = L1;
    } else {
        STATE = SERVE1;
    }
    right = true;
    serve1 = true;
    break; //end

case L1:
    if(right && serve1){ //for serving only 
        STATE = L2;
        !serve1;
    } else if(btn1_pressed && right && !serve1){ //for returning
        STATE = L2;
        if(GAMEPERIOD >> 100){
            GAMEPERIOD = GAMEPERIOD - 5; //soeed up return speed after every volley
        }
   } else if(!btn1_pressed && !serve1){
        STATE = WIN2;
        winner = 1;
   } else if(!btn1_pressed && serve1){
        STATE = L1;
   } else {
        STATE = L1;
   }
break;

case L2:
    if(right && !btn2_pressed){
        STATE = L3;
        right = true;
    } else if(right && btn2_pressed){
        STATE = L3;
        winner = 0; //set right as pot. winner
    } else if(!right && !btn1_pressed){ //going left now 
        STATE = L1;
        right = 1;
    } else if(!right && btn1_pressed) {
        STATE = L1;
        winner = 1; //set left as pot. winner
    }
break;

case L3:
    if(right && !btn2_pressed){
        STATE = L4;
        right = true;
    } else if(right && btn2_pressed){
        STATE = L4;
        winner = 0;
    } else if(!right && !btn1_pressed){ //going left now 
        STATE = L2;
        right = 0;
    } else if(!right && btn1_pressed) {
        STATE = L1;
        winner = 1;
    }
break;

case L4:
    if(right && !btn2_pressed){
        STATE = L5;
        right = true;
    } else if(right && btn2_pressed){
        STATE = L5;
        winner = 0;
    } else if(!right && !btn1_pressed){ //going left now 
        STATE = L3;
        right = 0;
    } else if(!right && btn1_pressed) {
        STATE = L3;
        winner = 1;
    }
break;

case L5:
    if(right && !btn2_pressed){
        STATE = L6;
        right = true;
    } else if(right && btn2_pressed){
        STATE = L6;
        winner = 0;
    } else if(!right && !btn1_pressed){ //going left now 
        STATE = L4;
        right = 0;
    } else if(!right && btn1_pressed) {
        STATE = L4;
        winner = 1;
    }
break;

case L6:
    if(right && !btn2_pressed){
        STATE = L7;
        right = true;
    } else if(right && btn2_pressed){
        STATE = L7;
        winner = 0;
    } else if(!right && !btn1_pressed){ //going left now 
        STATE = L5;
        right = 0;
    } else if(!right && btn1_pressed) {
        STATE = L5;
        winner = 1;
    }
break;

case L7:
    if(right && !btn2_pressed){
        STATE = L8;
        right = true;
    } else if(right && btn2_pressed){
        STATE = L8;
        winner = 0;
    } else if(!right && !btn1_pressed){ //going left now 
        STATE = L6;
        right = 0;
    } else if(!right && btn1_pressed) {
        STATE = L6;
        winner = 1;
    }
break;

case L8:
    if(right && serve1){ //for serving only 
        STATE = L2;
        !serve1;
    } else if(btn1_pressed && right && !serve1){ //for returning
        STATE = L2;
        if(GAMEPERIOD >> 100){
            GAMEPERIOD = GAMEPERIOD - 5; //soeed up return speed after every volley
        }
   } else if(!btn1_pressed && !serve1){
        STATE = WIN2;
        winner = 1;
   } else if(!btn1_pressed && serve1){
        STATE = L1;
   } else {
        STATE = L1;
   }
break;

case L8:
    if (!btn2_pressed){
        STATE = WIN1;
        winner = 0;
    } else if (btn_pressed2 && !dir_right){
        STATE = L7;
    }
break;

case WIN1:

break;

case WIN2:

break;


} //switch

} //tickfct