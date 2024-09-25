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
    printf("Game Starts: Choosing Server...");
        if(rand() % 2 == 0){
            serve1 = true;
        } else {
            serve1 = false;
        }
        STATE = serve1 ? SERVE1 : SERVE2;
    break;

case SERVE1:
    printf("Serve 1");
    led_out_write(0b10000000);
    if(btn1_pressed){
        right = true;
        serve1 = true;
        STATE = L2;
    } 
    
    break; //end

case SERVE2:
    printf("Serve 2");
    led_out_write(0b00000001);
    if(btn2_pressed){
        right = false;
        serve1 = false;
        STATE = L7;
    } 
    break; //end

case L1:
    printf("L1");
    if(btn1_pressed && !right){
        GAMEPERIOD = (GAMEPERIOD > 100) ? GAMEPERIOD - 5 : GAMEPERIOD;
        STATE = L2;
        right = true;
    } else if(!btn1_pressed && !right){
        winner = false;
        STATE = WIN2a;
    }
break;

//leds 2-8 have no feedback from button input 
case L2:
    printf("L2");
    if(right){
        STATE = L3;
    } else if(!right){
        STATE = L1;
    }
break;

case L3:
    printf("L3");
    if(right){
        STATE = L4;
    } else if(!right){
        STATE = L2;
    }
break;

case L4:
    printf("L4");
    if(right){
        STATE = L5;
    } else if(!right){
        STATE = L3;
    }
break;

case L5:
    printf("L5");
    if(right){
        STATE = L6;
    } else if(!right){
        STATE = L4;
    }
break;

case L6:
    printf("L6");
    if(right){
        STATE = L7;
    } else if(!right){
        STATE = L5;
    }
break;

case L7:
    printf("L7");
    if(right){
        STATE = L8;
    } else if(!right){
        STATE = L6;
    }
break;

case L8:
    printf("L8");
    if (!btn2_pressed && right){
        GAMEPERIOD = (GAMEPERIOD > 100) ? GAMEPERIOD - 5 : GAMEPERIOD;
        winner = true;
        STATE = WIN1a;
    } else if (btn2_pressed && right){
        right = false;
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
    STATE = WIN1c;
break;
case WIN1c:
    printf("Player 1 Wins!");
    led_out_write(0b10000000);
    STATE = WIN1d;
break;
case WIN1d:
    led_out_write(0b00000000);
    STATE = WIN1e;
break;
case WIN1e:
    printf("Player 1 Wins!");
    led_out_write(0b10000000);
    STATE = WIN1f;
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
    STATE = WIN2c;
break;
case WIN2c:
    printf("Player 2 Wins!");
    led_out_write(0b00000001);
    STATE = WIN2d;
break;
case WIN2d:
    led_out_write(0b00000000);
    STATE = WIN2e;
break;
case WIN2e:
    printf("Player 2 Wins!");
    led_out_write(0b00000001);
    STATE = WIN2f;
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
        led_out_write(0b00000001);
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

        if(timer_elapsed_ms(t1, t2) >= GAMEPERIOD) {
            TickFct_Pong();
            t1 = t2;
        }
    }
}