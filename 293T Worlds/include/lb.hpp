#include "main.h"
#include "pros/rotation.h"

extern void liftControl();
extern void nextState();
extern void hangingFunc();
extern void lbTip();
extern void lbUntip();
extern void lbDecore6thRing();
extern void autoLadderTouch();

extern int currState;
extern int target;

extern void lbAsyncControl(void * param);

//Motor & Sensor
extern pros::Motor lb;
extern pros::Rotation rotationSensor;