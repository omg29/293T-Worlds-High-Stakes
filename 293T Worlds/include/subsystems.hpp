#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

//clamp
inline pros::adi::Pneumatics clamp1('H', false);

//doinkers
inline pros::adi::Pneumatics leftDoinker('G', false);
inline pros::adi::Pneumatics rightDoinker('F', false);

//intake raise
inline pros::adi::Pneumatics intakeRaise('C', false);

//distance reset sensors
inline pros::Distance yDistanceSensor(6);