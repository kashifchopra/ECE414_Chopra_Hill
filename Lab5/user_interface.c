#include "pico/stdlib.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <stdio.h>


void drawUI(){

    char buffer1[30];
    char buffer2[30];
    char buffer3[30];
    char buffer4[30];
    char buffer5[30];
    char buffer6[30];
    char buffer7[30];
    char buffer8[30];
    char buffer9[30];
    char buffer10[30];
    char buffer11[30];
    char buffer12[30];
    char buffer13[30];
    char buffer14[30];
    char buffer15[30];
    char buffer16[30];

    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9340_BLACK);  
    tft_setTextSize(2);

//////////////////////////

    // Display 7
    tft_setCursor(0,0);
    tft_fillRoundRect(10, 40, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(10, 40, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(42, 60);
    sprintf(buffer1, "%d", 7);
    tft_writeString(buffer1);

    // Display 8
    tft_setCursor(0,0);
    tft_fillRoundRect(85, 40, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(85, 40, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(117,60);
    sprintf(buffer2, "%d", 8);
    tft_writeString(buffer2);

    // Display 9
    tft_setCursor(0,0);
    tft_fillRoundRect(160, 40, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(160, 40, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(192,60);
    sprintf(buffer3, "%d", 9);
    tft_writeString(buffer3);
    
    // Display +
    tft_setCursor(0,0);
    tft_fillRoundRect(245, 40, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(245, 40, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(277,60);
    sprintf(buffer4, "%c", "+");
    tft_writeString("+");

///////////////////////////

    // Display 4
    tft_setCursor(0,0);
    tft_fillRoundRect(10, 90, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(10, 90, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(42, 110);
    sprintf(buffer5, "%d", 4);
    tft_writeString(buffer5);

    // Display 5
    tft_setCursor(0,0);
    tft_fillRoundRect(85, 90, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(85, 90, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(117,110);
    sprintf(buffer6, "%d", 5);
    tft_writeString(buffer6);

    // Display 6
    tft_setCursor(0,0);
    tft_fillRoundRect(160, 90, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(160, 90, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(192,110);
    sprintf(buffer7, "%d", 6);
    tft_writeString(buffer7);
    
    // Display -
    tft_setCursor(0,0);
    tft_fillRoundRect(245, 90, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(245, 90, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(277,110);
    sprintf(buffer8, "%c", "-");
    tft_writeString("-");

/////////////////////////////////

    // Display 1
    tft_setCursor(0,0);
    tft_fillRoundRect(10, 140, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(10, 140, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(42, 160);
    sprintf(buffer9, "%d", 1);
    tft_writeString(buffer9);

    // Display 2
    tft_setCursor(0,0);
    tft_fillRoundRect(85, 140, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(85, 140, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(117,160);
    sprintf(buffer10, "%d", 2);
    tft_writeString(buffer10);

    // Display 3
    tft_setCursor(0,0);
    tft_fillRoundRect(160, 140, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(160, 140, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(192,160);
    sprintf(buffer11, "%d", 3);
    tft_writeString(buffer11);
    
    // Display *
    tft_setCursor(0,0);
    tft_fillRoundRect(245, 140, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(245, 140, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(277,160);
    sprintf(buffer12, "%c", "X");
    tft_writeString("X");

/////////////////////////////////

// Display 0
    tft_setCursor(0,0);
    tft_fillRoundRect(10, 190, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(10, 190, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(42, 210);
    sprintf(buffer13, "%d", 0);
    tft_writeString(buffer13);

    // Display c
    tft_setCursor(0,0);
    tft_fillRoundRect(85, 190, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(85, 190, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(117,210);
    sprintf(buffer14, "%s", "C");
    tft_writeString("C");

    // Display =
    tft_setCursor(0,0);
    tft_fillRoundRect(160, 190, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(160, 190, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(192,210);
    sprintf(buffer15, "%c", "=");
    tft_writeString("=");
    
    // Display /
    tft_setCursor(0,0);
    tft_fillRoundRect(245, 190, 65, 40, 10, ILI9340_BLUE);
    tft_drawRoundRect(245, 190, 65, 40, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(277,210);
    sprintf(buffer16, "%c", "/");
    tft_writeString("/");

    //HardCoded Num example
    //tft_setCursor(230, 2);
    //tft_writeString("kasheef");
/////////////////////////////////

    //RECT COORDINATES: 
        //   10       85      160     245
        //40 7        8       9       +


        //90 4        5       6       -


        //140 1       2       3       *


        //190 0       c       =       /

}

