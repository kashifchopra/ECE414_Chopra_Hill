#include "PIR.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <stdio.h>
#include <stdbool.h>


//NEED TIMER MODULE FOR INTERNAL COUNTER
//   - while (WHILE LOOP) in occupied, every time internal counter clocks a minute,
//     run check


//           while(1){
// 
//               if(motion){
//                  occ_tmr_cnt = 0;
//               }
//               if(!motion && occ_tmr_cnt < 20){
//                  occ_tmr_cnt++;
//                  internal_cnt = 0;
//               } else if (!motion && occ_tmr_cnt >= 20){
//                  STATE = UNOCCUPIED;
//               }
//              
//          
//           }


bool motion; //PIR data, high or low
bool occupied; //boolean flag
uint32_t internal_cnt; //counter incremented once every second in OCCUPIED state
uint32_t occ_tmr_cnt; //cycles of no motion
uint32_t timer_limit = 20; //SUBJECT TO CHANGE FOR TESTING PURPOSES
const uint32_t pir_gpio = 16;



void pir_init(){ //low level code to initialize port
   adc_init();
   gpio_set_dir(pir_gpio, GPIO_IN);
}

bool pir_read(){ //boolean output of pir
    if(gpio_get(pir_gpio)){
        motion = true;
    } else {
        motion = false;
    }
    return motion;
}

static enum STATE {
    INIT,
    UNOCC,
    OCC
}

void tickFnct_pir(){








}


//function to get pir data, HIGH will flag motion var to true, vice versa





