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

  FrontRight.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, true);

  FrontRight.rotateFor(directionType::fwd, 360, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, -360, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, true);
  
  FrontRight.rotateFor(directionType::fwd, 360, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, -360, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, true);
  
  FrontRight.rotateFor(directionType::fwd, 360, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, -360, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 2000, rotationUnits::deg, 50, velocityUnits::pct, true);
  

}
