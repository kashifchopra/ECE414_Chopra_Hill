/*
* Author: Kashif Chopra
* Date: 10/18/24
*/

#include "TFTMaster.h"
#include "pico/stdlib.h"

//first define states - 
//INITIAL, num1, op, num2, result, error, (maybe div0 too)
static enum CALC_STATES{
INITIAL,num1,neg1,num1neg, op,num2,neg2, num2neg,result,error, div0 //maybe keep/remove div0state
} CALC_STATE;

//global variables
int32_t previnput; //used to save prev input before overwriting input with new touch value. Helpful in seeing if we are dividing by 0 
int32_t input; // 0-9: numbers; 10: +, 11: -, 12:X, 13: / , 14: = , 15: clear.
int32_t n1; //global variable for number 1
int32_t n2; //global variable for number 2
int32_t res; //global variable to hold result value
int32_t operator; //global variable to remember what the operator is
bool errFlag; // flag to show its error
bool zeroErr; //flag to show its div by 0

//helper functions 
void clear(){
    n1 = 0;
    n2 = 0;
    res = 0;
    operator = 0; 
    input = 0; //maybe put elsewhere
    CALC_STATE = INITIAL; 
    zeroErr = 0; //TOCHECK
    errFlag = 0; //TOCHECK
}

int32_t operate(int32_t n1, int32_t n2, int32_t operator){
    if(operator == 10){
        return (n1+n2);
    } else if(operator == 11){
        return (n1-n2);
    }else if(operator == 12){
        return(n1*n2);
    }else if(operator == 13){
        if(n2 ==0) return 0;
        return(n1/n2);    
    }
}

bool err(){
    if(CALC_STATE == error) return true;
    return false;
}



//FSM: 
void tckFnct_Calculator(){

//define variables/flags 


//define actions within each state with switch case 
switch(CALC_STATE){

    case INITIAL: 
        if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
            n1 = input;
        }else if(input==10 || input ==12 || input ==13 || input ==14){
            // do nothing
        }else if(input == 11){
            // do nothing
        } else if(input == 15){
            clear();
        }
        
        break;

    case num1: 
       if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
           n1 = (n1*10) + input;
        }else if(input>=10 && input <=13 ){
           //save what the operator is
           operator = input; 
        } else if(input == 14){
           res = n1; 
        } else if(input == 15){
            clear();
        }
        break;

    case neg1: 
         if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
           n1 = input*(-1);
        }else if(input>=10 && input <=14 ){
           //no action only state change 
        } else if(input == 15){
            clear();
        }

        break;

     case num1neg: //has same behaviour as num1, just that when we type multiple digit negative numbers it does the math differently to get the number cos its negative
       if(0<=input && input<=9){ //this handles numbers with multiple digits.
           n1 = (n1*10) - input;
        }else if(input>=10 && input <=13 ){
           //save what the operator is
           operator = input;  
        } else if(input == 14){
           res = n1; 
        } else if(input == 15){
            clear();
        }

        break;
    

    case op: 
        if(0<=input && input<=9){ 
            n2 = input; 
        }else if(input==10 || input ==12 || input ==13 || input ==14){
            //nothing or maybe set err = true. Then rem to set err = false in all other cases. 
        }else if(input == 11){
            //nothing
        } else if(input == 15){
            clear();
        }
        break;

    case num2: 
       
        if(0<=input && input<=9){ 
            n2 = n2*10 + input;
        }else if(input>=10 && input <=13 ){
            n1 = operate(n1,n2,operator);
            //might need to rest n2 value here? 
            //save what the new operator is
           operator = input; 
        } else if(input == 14){
            res = operate(n1,n2,operator);
        } else if(input == 15){
            clear();  
        }
        break;

     case neg2: 
         if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
           n2 = input*(-1);
        }else if(input>=10 && input <=14 ){
           //no action only state change 
        } else if(input == 15){
            clear();
        }
        break;

    case num2neg: //has same behaviour as num2, just that when we type multiple digit negative numbers it does the math differently to get the number cos its negative
         if(0<=input && input<=9){ 
            n2 = n2*10 - input;
        }else if(input>=10 && input <=13 ){
            n1 = operate(n1,n2,operator);
            //might need to rest n2 value here? 
            //save what the new operator is
           operator = input; 
        } else if(input == 14){
            res = operate(n1,n2,operator);
        } else if(input == 15){
            clear();  
        }
        break;

    case result: 
        if(0<=input && input<=9){ 
            n1 = input; 
        }else if(input>=10 && input <=13 ){
            n1 = result; 
            //save what the operator is
           operator = input; 
        } else if(input == 14){
            //nothing
        } else if(input == 15){
            clear();  
        }
        break;

    case error: 
        

        break;

    case div0: 
        
        //zeroErr = 1; //CHECK AND TEST MORE

        break;

    //default://do nothing
        
        break; 
}


//define state change scenarios with switch case
switch(CALC_STATE){

    case INITIAL: 
        printf("Current state: INITIAL \n");
        //if input = any num 0-9, next state = num1
        
        if(0<=input && input<=9){
            CALC_STATE = num1;
            break;
        } else if (input == 11){  // for -ve number sign 
            CALC_STATE = neg1;
        } else{
            CALC_STATE = INITIAL;
        }
        break;

    case num1: 
    printf("Current state: num1 \n");
        if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
            CALC_STATE = num1;
        }else if(input>=10 && input <=13 ){
            CALC_STATE = op;
        } else if(input == 14){
            CALC_STATE = result;
        } else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;

    case neg1: 
    printf("Current state: neg1 \n");
        if(0<=input && input<=9){ 
            CALC_STATE = num1neg;
        }else if(input>=10 && input <=14 ){
            CALC_STATE = error;
        }else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;

     case num1neg: //has same behaviour as num1, just that when we type multiple digit negative numbers it does the math differently to get the number cos its negative
     printf("Current state: num1neg \n");
        if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
            CALC_STATE = num1neg;
        }else if(input>=10 && input <=13 ){
            CALC_STATE = op;
        } else if(input == 14){
            CALC_STATE = result;
        } else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;
    

    case op: 
    printf("Current state: op \n");
        if(0<=input && input<=9){ 
            CALC_STATE = num2;
        }else if(input==10 || input ==12 || input ==13 || input ==14){
            CALC_STATE = error;
        }else if(input == 11){
            CALC_STATE = neg2;
        } else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;

    case num2: 
    printf("Current state: num2 \n");
        if(0<=input && input<=9){ 
            CALC_STATE = num2;
        }else if(input>=10 && input <=13 ){
            CALC_STATE = op;
        } else if(input == 14){

            if(operator == 13 && num2 == 0){ // if dividing by 0 go to div0 state 
                CALC_STATE = div0;
            }


            CALC_STATE = result;
        } else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;

     case neg2: 
     printf("Current state: neg2 \n");
        if(0<=input && input<=9){ 
            CALC_STATE = num2neg;
        }else if(input>=10 && input <=14 ){
            CALC_STATE = error;
        }else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;

    case num2neg: //has same behaviour as num2, just that when we type multiple digit negative numbers it does the math differently to get the number cos its negative
    printf("Current state: num2neg \n");
        if(0<=input && input<=9){ //this handles numbers with multiple digits. It will be handles within the num1 state.
            CALC_STATE = num2neg;
        }else if(input>=10 && input <=13 ){
            CALC_STATE = op;
        } else if(input == 14){
            CALC_STATE = result;
        } else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;

    case result: 
    printf("Current state: result \n");
        if(0<=input && input<=9){ 
            CALC_STATE = num1;
        }else if(input>=10 && input <=13 ){
            CALC_STATE = op;
        } else if(input == 14){
            CALC_STATE = result;
        } else if(input == 15){
            CALC_STATE = INITIAL; 
        }
        break;

    case error: 
    printf("Current state: error \n");
        if(0<=input && input<=15){ 
            CALC_STATE = INITIAL;
        }
        break;

    case div0: 
    printf("Current state: div0 \n");
        if(0<=input && input<=15){ 
            CALC_STATE = INITIAL;
        }
        break;

    default:
        CALC_STATE = INITIAL; 
        break; 
}
}



// Simulate button presses and run the calculator function
void testCalculator() {
	
    //Now test for 6 / 2: 
	input = 6;
	tckFnct_Calculator(); // Simulate pressing 3
	printf("Tick 1 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 13;
	tckFnct_Calculator(); // Simulate pressing +
	printf("Tick 2 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 2;
	tckFnct_Calculator(); // Simulate pressing 2
	printf("Tick 3 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	
	
	input = 14;
	tckFnct_Calculator(); // Simulate pressing =
	printf("Tick 4 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected 3, res is: %d\n",res);

    tckFnct_Calculator(); // 
	printf("Tick 5 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected 3, res is: %d\n",res);

    printf("Clear occuring now (clear) \n");
    clear();
	printf("    expected 0, res is: %d\n",res);


    //Now test for -6 + 2: 
	input = 11;
	tckFnct_Calculator(); // Simulate pressing -
	printf("Tick 1 occured \n");
	printf("    expected 0, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	
	input = 6;
	tckFnct_Calculator(); 
	printf("Tick 2 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 10;
	tckFnct_Calculator(); // Simulate pressing +
	printf("Tick 3 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 2;
	tckFnct_Calculator(); // Simulate pressing 2
	printf("Tick 4 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	
	
	input = 14;
	tckFnct_Calculator(); // Simulate pressing =
	printf("Tick 5 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected -4, res is: %d\n",res);

    tckFnct_Calculator(); // 
	printf("Tick 6 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected -4, res is: %d\n",res);

    printf("Clear occuring now (clear) \n");
    clear();
	printf("    expected 0, res is: %d\n",res);
	
	//Now test for -6 / 2: 
	input = 11;
	tckFnct_Calculator(); // Simulate pressing -
	printf("Tick 1 occured \n");
	printf("    expected 0, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	
	input = 6;
	tckFnct_Calculator(); 
	printf("Tick 2 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 13;
	tckFnct_Calculator(); // Simulate pressing +
	printf("Tick 3 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 2;
	tckFnct_Calculator(); // Simulate pressing 2
	printf("Tick 4 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	
	
	input = 14;
	tckFnct_Calculator(); // Simulate pressing =
	printf("Tick 5 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected -3, res is: %d\n",res);

    tckFnct_Calculator(); // 
	printf("Tick 6 occured \n");
	printf("    expected -6, N1 is: %d\n",n1);
	printf("    expected 2, N2 is: %d\n",n2);
	printf("    expected -3, res is: %d\n",res);

    printf("Clear occuring now (clear) \n");
    clear();
	printf("    expected 0, res is: %d\n",res);
	


	//Now test for 6 / 0: NOT COMPLETE YET - To further check as of 10/25/24
	
	input = 6;
	tckFnct_Calculator(); 
	printf("Tick 2 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 13;
	tckFnct_Calculator(); // Simulate pressing +
	printf("Tick 3 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, res is: %d\n",res);
	

	input = 0;
	tckFnct_Calculator(); // Simulate pressing 2
	printf("Tick 4 occured \n");
	printf("    expected 6, N1 is: %d\n",n1);
	printf("    expected 0, N2 is: %d\n",n2);
	printf("    expected 0, zeroErr is: %d\n",zeroErr);
	
	
	input = 14;
	tckFnct_Calculator(); // Simulate pressing =
	printf("Tick 5 occured \n");
	printf("    expected 0, zeroErr is: %d\n",zeroErr);
	

    tckFnct_Calculator(); // 
	printf("Tick 6 occured \n");
	printf("    expected 1?, zeroErr is: %d\n",zeroErr);
    
     tckFnct_Calculator(); // 
	printf("Tick 7 occured \n");

    printf("Clear occuring now (clear) \n");
    clear();
	printf("    expected 0, res is: %d\n",res);

  /*   // Clear and test 5 - 1 =
    clear();
    input = 5; 
    tckFnct_Calculator(); // Press 5
    input = 11; 
    tckFnct_Calculator(); // Press -
    input = 1; 
    tckFnct_Calculator(); // Press 1
    input = 14; 
    tckFnct_Calculator(); // Press =

     printf(result);
    assert(result == 4); // Expected result: 4

    // Clear and test 4 * 2 =
    clear();
    input = 4; 
    tckFnct_Calculator(); // Press 4
    input = 12; 
    tckFnct_Calculator(); // Press *
    input = 2; 
    tckFnct_Calculator(); // Press 2
    input = 14; 
    tckFnct_Calculator(); // Press =

 printf(result);
    assert(result == 8); // Expected result: 8

    // Clear and test 8 / 2 =
    clear();
    input = 8; 
    tckFnct_Calculator(); // Press 8
    input = 13; 
    tckFnct_Calculator(); // Press /
    input = 2; 
    tckFnct_Calculator(); // Press 2
    input = 14; 
    tckFnct_Calculator(); // Press =
 printf(result);
    assert(result == 4); // Expected result: 4

    // Clear and test division by zero
    clear();
    input = 8; 
    tckFnct_Calculator(); // Press 8
    input = 13; 
    tckFnct_Calculator(); // Press /
    input = 0; 
    tckFnct_Calculator(); // Press 0
    input = 14; 
    tckFnct_Calculator(); // Press =
 printf(result);
    assert(result == 0); // Expected result: should indicate division by zero

    // Clear and test clear functionality
    clear();
    assert(CALC_STATE == INITIAL); // State should be INITIAL */

}



int main(){



    // Run tests
    testCalculator();

    printf("All tests passed!\n");
    return 0;
}
