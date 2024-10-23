#ifndef TCKFNCT_CALCULATOR
#define TCKFNCT_CALCULATOR

#include "TFTMaster.h"
#include "pico/stdlib.h"
#include "stdint.h"

//helper functions 
void clear();
int32_t operate(int32_t n1, int32_t n2, int32_t input);
bool err();

//FSM for all calculator operations
void tckFnct_Calculator();


#endif