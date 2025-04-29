#include "main.h"
#include "pros/motor_group.hpp"

extern pros::Motor bottomIntake;

extern pros::Motor upperIntake;

extern pros::MotorGroup intake;
extern pros::Distance distanceSensor;

extern int allianceColor;
extern void cycleAllianceColor();
extern int seenColor;

extern void setIntake(int bottomSpeed, int upperSpeed);

extern void asyncIntakeControl(void * param);
