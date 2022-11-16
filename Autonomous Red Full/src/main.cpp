/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\baile                                            */
/*    Created:      Fri Aug 26 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  FrontRight.rotateFor(directionType::rev, 720, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 720, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::rev, 540, rotationUnits::deg, 50, velocityUnits::pct, true);
  UpperIntake.rotateFor(directionType::rev, 95, rotationUnits::deg, 80, velocityUnits::pct, false);
  LowerIntake.rotateFor(directionType::rev, 95, rotationUnits::deg, 80, velocityUnits::pct, true);
  UpperIntake.rotateFor(directionType::fwd, 40, rotationUnits::deg, 50, velocityUnits::pct, false);
  LowerIntake.rotateFor(directionType::fwd, 40, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontRight.rotateFor(directionType::fwd, 5600, rotationUnits::deg, 75, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 5600, rotationUnits::deg, 75, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::fwd, 960, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 960, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::rev, 360, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 360, rotationUnits::deg, 50, velocityUnits::pct, true);
  UpperIntake.rotateFor(directionType::rev, 95, rotationUnits::deg, 80, velocityUnits::pct, false);
  LowerIntake.rotateFor(directionType::rev, 95, rotationUnits::deg, 80, velocityUnits::pct, true);
  UpperIntake.rotateFor(directionType::fwd, 40, rotationUnits::deg, 50, velocityUnits::pct, false);
  LowerIntake.rotateFor(directionType::fwd, 40, rotationUnits::deg, 50, velocityUnits::pct, false);

  

}
