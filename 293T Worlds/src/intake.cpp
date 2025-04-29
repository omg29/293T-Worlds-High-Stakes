#include "main.h"
#include "intake.hpp"
#include <cmath>
#include <cstdint>
#include <type_traits>
#include "pros/distance.hpp"
#include "pros/misc.h"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/optical.h"
#include "pros/optical.hpp"
#include "pros/rtos.hpp"
#include "pros/screen.hpp"
#include "subsystems.hpp"
#include "lb.hpp"

//intake motors
pros::Motor bottomIntake(11);
pros::Motor upperIntake(14);

//color sensor
pros::Optical colorSensor(22);

//distance sensor
pros::Distance distanceSensor(3);

int bottomIntakeSpeed;
int upperIntakeSpeed;

//color sort variables
bool ringDetected = false;
bool ringInIntake = false;

int allianceColor = 0;
int seenColor = 2;

void setIntake(int bottomSpeed, int upperSpeed){
    bottomIntakeSpeed = bottomSpeed;
    upperIntakeSpeed = upperSpeed;
}

void cycleAllianceColor(){
    allianceColor += 1;
    if (allianceColor == 3){
        allianceColor = 0;
    }
}

//anti jam timer
uint32_t lastCheckTime = pros::millis();

//intake async control
void asyncIntakeControl(void * param){
    bool wrongRing = false;
    int elapsedTime = 0;

    while(true){
        colorSensor.set_led_pwm(100);
        //run intake
        upperIntake.move(upperIntakeSpeed);
        bottomIntake.move(bottomIntakeSpeed);

        //anti jam
        if(pros::millis() - lastCheckTime >= 500){
            if((upperIntake.get_efficiency()/100 <=0.2) && (upperIntakeSpeed > 10) && (target != 27)){
                upperIntake.move(-127);
                pros::delay(300);
                upperIntake.move(127);
                lastCheckTime = pros::millis();
            }
            else{
                lastCheckTime = pros::millis();
            }
        }

        //color sort
        /*
        if((colorSensor.get_hue() > 340) || (colorSensor.get_hue() < 20)){
            seenColor = 0;
        }
        else if((colorSensor.get_hue() > 215) && (colorSensor.get_hue() < 255)){
            seenColor = 1;
        }
        else{
            seenColor = 2;
        }

        if(distanceSensor.get() < 20){
            ringDetected = true;
            ringInIntake = true;
        }
        else{
            ringDetected = false;
        }
        if((distanceSensor.get() > 30) && ringInIntake){
            if(((allianceColor == 0) && (seenColor == 1)) || ((allianceColor == 1) && (seenColor == 0))){
                upperIntake.move(-127);
                pros::delay(250);
                ringDetected = false;
                ringInIntake = false;
            } 
        }
        else{
            pros::delay(1);
        }*/
        
        //delay
        pros::delay(20);
    }
}