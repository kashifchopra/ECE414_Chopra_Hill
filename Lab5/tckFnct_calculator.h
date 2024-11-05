#ifndef TCKFNCT_CALCULATOR
#define TCKFNCT_CALCULATOR

#include "TFTMaster.h"
#include "pico/stdlib.h"
#include "stdint.h"

extern int32_t previnput; //used to save prev input before overwriting input with new touch value. Helpful in seeing if we are dividing by 0 
extern int32_t input; // 0-9: numbers; 10: +, 11: -, 12:X, 13: / , 14: = , 15: clear.
extern int32_t n1; //global variable for number 1
extern int32_t n2; //global variable for number 2
extern int32_t res; //global variable to hold result value
extern int32_t operator; //global variable to remember what the operator is
extern bool errFlag; // flag to show its error
extern bool zeroErr; //flag to show its div by 0
extern int32_t stateVar;  


//helper functions 
void clear();
int32_t operate(int32_t n1, int32_t n2, int32_t input);
bool err();

//FSM for all calculator operations
void tckFnct_Calculator();

int32_t operate(int32_t n1, int32_t n2, int32_t operator);
void testCalculator(); 


#endif