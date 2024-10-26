//module to return an integer value to FSM for button press based on position of the touchscreen touched. 
#include "ts_lcd.h"
#include "tckFnct_calculator.h"
#include "hardware/gpio.h"
#include "TFTMaster.h"
#include <stdio.h>
#include "pico/stdlib.h"

// int input(){
//      struct TSPoint p;
//                 p.x = 0;
//                 p.y = 0;
//                 p.z = 0;
    
//     uint32_t savedX;
//     uint32_t savedY;

//     if(get_ts_lcd(&p.z)){ //sense press 
//         savedY = interpolateY(p.x); //get x and y touch coordinates 
//         savedX = interpolateX(p.y);
//     }

//     return getInput(savedX, savedY); //plug into getInput, return specific button number
// }

int getInput(int x, int y){
    //FIRST ROW 
    if((x > 10 && x < 75) && (y > 40 && y < 80)){
        return 7;
    }
    if((x > 85 && x < 150) && (y > 40 && y < 80)){
        return 8;
    }
    if((x > 160 && x < 225) && (y > 40 && y < 80)){
        return 9;
    }
    if((x > 245 && x < 310) && (y > 40 && y < 80)){
        return 10;
    }

    //SECOND ROW 
    if((x > 10 && x < 75) && (y > 90 && y < 130)){
        return 4;
    }
    if((x > 85 && x < 150) && (y > 90 && y < 130)){
        return 5;
    }
    if((x > 160 && x < 225) && (y > 90 && y < 130)){
        return 6;
    }
    if((x > 245 && x < 310) && (y > 90 && y < 130)){
        return 11;
    }

    //THIRD ROW 
    if((x > 10 && x < 75) && (y > 140 && y < 180)){
        return 1;
    }
    if((x > 85 && x < 150) && (y > 140 && y < 180)){
        return 2;
    }
    if((x > 160 && x < 225) && (y > 140 && y < 180)){
        return 3;
    }
    if((x > 245 && x < 310) && (y > 140 && y < 180)){
        return 12;
    }

    //FOURTH ROW    
    if((x > 10 && x < 75) && (y > 190 && y < 230)){
        return 0;
    }
    if((x > 85 && x < 150) && (y > 190 && y < 230)){
        return 15;
    }
    if((x > 160 && x < 225) && (y > 190 && y < 230)){
        return 14;
    }
    if((x > 245 && x < 310) && (y > 190 && y < 230)){
        return 13;
    }


}