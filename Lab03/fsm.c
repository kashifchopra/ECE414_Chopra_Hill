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
    WIN1a,
    WIN1b,
    WIN1c,
    WIN1d,
    WIN1e,
    WIN1f,
    WIN2a,
    WIN2b, 
    WIN2c,
    WIN2d,
    WIN2e, 
    WIN2f
} STATE;

//set std game period 
u_int32_t GAMEPERIOD = 300;

void TickFct_Pong(){
    bool btn1_pressed = debounce_sw1_pressed();
    bool btn2_pressed = debounce_sw2_pressed();

    static bool serve1;
    static bool right; //directional boolean
    static bool winner; //boolean for accounting which side will be wiinner mid play. If 1 -> left wins. 

switch(STATE){

case INITIAL:
        serve1 = rand() % 2; // Randomly select serve
        state = serve1 ? SERVE1 : SERVE2;
    break;

case SERVE1:
    printf("Serve 1");
    led_out_write(0b10000000);
    if(btn1_pressed){
        STATE = L1;
    } 
    right = true;
    serve1 = true;
    break; //end

case SERVE2:
    printf("Serve 2");
    led_out_write(0b00000001);
    if(btn2_pressed){
        STATE = L8;
    } else if(!serve1 && !btn2_pressed){
        STATE = SERVE2; 
    } else if(!serve1 && btn2_pressed){
        STATE = L8;
    } else {
        STATE = SERVE2;
    }
    right = false;
    serve1 = false;
    break; //end

case L1:
    printf("L1");
    if(right && serve1){ //for serving only 
        STATE = L2;
        !serve1;
    } else if(btn1_pressed && right && !serve1){ //for returning
        STATE = L2;
        if(GAMEPERIOD > 100){
            GAMEPERIOD = GAMEPERIOD - 5; //soeed up return speed after every volley
        }
   } else if(!btn1_pressed && !serve1){
        STATE = WIN2a;
        winner = 1;
   } else if(!btn1_pressed && serve1){
        STATE = L1;
   } else {
        STATE = L1;
   }
break;

case L2:
    printf("L2");
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
    printf("L3");
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
    printf("L4");
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
    printf("L5");
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
    printf("L6");
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
    printf("L7");
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
    printf("L8");
    if (!btn2_pressed){
        STATE = WIN1a;
        winner = 0;
    } else if (btn2_pressed && !right){
        STATE = L7;
    }
break;

//win1 blink 
case WIN1a:
    GAMEPERIOD = 300;
    printf("Player 1 Wins!");
    led_out_write(0b10000000);
    STATE = WIN1b;
break;
case WIN1b:
    led_out_write(0b00000000);
    STATE = WIN1b;
break;
case WIN1c:
    printf("Player 1 Wins!");
    led_out_write(0b10000000);
    STATE = WIN1b;
break;
case WIN1d:
    led_out_write(0b00000000);
    STATE = WIN1b;
break;
case WIN1e:
    printf("Player 1 Wins!");
    led_out_write(0b10000000);
    STATE = WIN1b;
break;
case WIN1f:
    led_out_write(0b00000000);
    STATE = INITIAL;
break;

//win2 blink
case WIN2a:
    GAMEPERIOD = 300;
    printf("Player 2 Wins!");
    led_out_write(0b00000001);
    STATE = WIN2b;
break;
case WIN2b:
    led_out_write(0b00000000);
    STATE = WIN2b;
break;
case WIN2c:
    printf("Player 2 Wins!");
    led_out_write(0b00000001);
    STATE = WIN2b;
break;
case WIN2d:
    led_out_write(0b00000000);
    STATE = WIN2b;
break;
case WIN2e:
    printf("Player 2 Wins!");
    led_out_write(0b00000001);
    STATE = WIN2b;
break;
case WIN2f:
    led_out_write(0b00000000);
    STATE = INITIAL;
break;

} //switch

//coded leds for each state 
switch(STATE){
    case L1:
        led_out_write(0b10000000);
    break;
    case L2:
        led_out_write(0b01000000);
    break;
    case L3:
        led_out_write(0b00100000);
    break;
    case L4:
        led_out_write(0b00010000);
    break;
    case L5:
        led_out_write(0b00001000);
    break;
    case L6:
        led_out_write(0b00000100);
    break;
    case L7:
        led_out_write(0b00000010);
    break;
    case L8:
        led_out_write(0b10000001);
    break;
}


} // end tickfct



/* void main(){
    u_int32_t t1, t2, t1_debounce, t2_debounce;
    stdio_init_all();
    sw_in_init();
    led_out_init();
    bool led_state = true;
    static int DBPER = 50; //variable debouncer period 
    t1 = timer_read();
    t1_debounce = timer_read();

    while(1){
        t2 = timer_read();
        t2_debounce = timer_read();

        if(timer_elapsed_ms(t1_debounce, t2_debounce) > DBPER){
            debounce_sw1_tick();
            debounce_sw2_tick();
            t1_debounce = t2_debounce;
        }

        if(timer_elapsed_ms(t1, t2) < GAMEPERIOD){
            TickFct_Pong();
            t1 = t2;
        }
    }
} */


void main() {
    uint32_t t1, t2, t1_debounce, t2_debounce;
    stdio_init_all();
    sw_in_init();
    led_out_init();
    t1 = timer_read();
    t1_debounce = timer_read();

    while(1) {
        t2 = timer_read();

        if(timer_elapsed_ms(t1_debounce, t2) > 50) { // debounce period
            debounce_sw1_tick();
            debounce_sw2_tick();
            t1_debounce = t2;
        }

        if(timer_elapsed_ms(t1, t2) < GAMEPERIOD) {
            TickFct_Pong();
            t1 = t2;
        }
    }
}