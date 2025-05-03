#include "lb.hpp"
#include "main.h"

//lb
pros::Motor lb(13);
pros::Rotation rotationSensor(1);

const int numStates = 3;
int states[numStates] = {0, 27, 160/*, 190*/};
int currState = 0;
int target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
        }
    target = states[currState];
}

void lbTip(){
    target = 190;
    currState = 2;
}

void lbUntip(){
    target = 230;
    currState = 2;
}

void lbDecore6thRing(){
    target = 145;
    currState = 2;
}

void autoLadderTouch(){
    target = 100;
    currState = 2;
}

void liftControl() {
    double kp = 1.4;
    double error = target - (rotationSensor.get_position()/100);
    double velocity = kp * error;
    lb.move(velocity);
}

void lbAsyncControl(void * param){
    while(true){
      liftControl();
      pros::delay(10);
    }
}