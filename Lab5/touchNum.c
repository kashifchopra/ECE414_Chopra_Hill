//module to return an integer value to FSM for button press based on position of the touchscreen touched. 

int touchRead(int x, int y){

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
        return 7;
    }
    if((x > 85 && x < 150) && (y > 90 && y < 130)){
        return 8;
    }
    if((x > 160 && x < 225) && (y > 90 && y < 130)){
        return 9;
    }
    if((x > 245 && x < 310) && (y > 90 && y < 130)){
        return 10;
    }






}