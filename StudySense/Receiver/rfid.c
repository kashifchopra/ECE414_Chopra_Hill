//goal - to read the tag of the RFID and store than in a global variable 


#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <stdio.h>
#include <stdbool.h>

//define SPI pins
#define SPI_PORT spi0
#define PIN_RST 0
#define PIN_SCK 4
#define PIN_MOSI 5
#define PIN_MISO 6

//#define PIN_CS //? using CS? 


//SPI setup and initialise 
//setup MISO, MOSI, SCK, etc


//initialise the RC522 



//Define pins 

//function to read the RFIS and save that value in the global variable 


void rfid_init(){
//stdio_init_all(); //will probably be done in a top level function 
}


void rfid_read(){

}