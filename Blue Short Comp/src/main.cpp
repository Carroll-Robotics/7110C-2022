/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// FrontLeft            motor         1
// FrontRight           motor         10
// ClawMotor            motor         3
// ArmMotor             motor         8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void autonomous(void) {
  //insert code
  FrontRight.rotateFor(directionType::rev, 840, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 840, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::fwd, 540, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 540, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::rev, 360, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 360, rotationUnits::deg, 50, velocityUnits::pct, true);
  UpperIntake.rotateFor(directionType::rev, 90, rotationUnits::deg, 75, velocityUnits::pct, false);
  LowerIntake.rotateFor(directionType::rev, 90, rotationUnits::deg, 75, velocityUnits::pct, true);
  UpperIntake.rotateFor(directionType::fwd, 40, rotationUnits::deg, 50, velocityUnits::pct, false);
  LowerIntake.rotateFor(directionType::fwd, 40, rotationUnits::deg, 50, velocityUnits::pct, false);

}

int LauncherSpeed = 350;
void whenControllerL1Pressed() {
  LowerIntake.spin(forward);
  UpperIntake.spin(forward);
  waitUntil(!Controller1.ButtonL1.pressing());
  LowerIntake.stop();
  UpperIntake.stop();
}

void whenControllerL2Pressed() {
  LowerIntake.spin(reverse);
  UpperIntake.spin(reverse);
  waitUntil(!Controller1.ButtonL2.pressing());
  LowerIntake.stop();
  UpperIntake.stop();
}
void whenControllerR1Pressed() {
  LauncherSpeed += 50;
}

void whenControllerR2Pressed() {
  LauncherSpeed -= 50;
}
void whenControllerButtonAPressed() {
  LauncherSpeed = 0;
}

void usercontrol(void) {
    int deadband = 5;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();
    Launcher1.setVelocity(LauncherSpeed, rpm);
    Launcher2.setVelocity(LauncherSpeed, rpm);
    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      FrontLeft.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      FrontRight.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      FrontRight.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      FrontRight.setVelocity(rightMotorSpeed, percent);
    }
    if (Controller1.ButtonR1.pressing()) {
      UpperIntake.spin(forward);
      LowerIntake.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      UpperIntake.spin(reverse);
      LowerIntake.spin(reverse);
    } else {
      UpperIntake.stop();
      LowerIntake.stop();
    }
    
    // Spin both motors in the forward direction.
    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    Launcher1.spin(forward);
    Launcher2.spin(forward);

    wait(25, msec);
    
  }
}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while(true) {
    wait(100, msec);
  }
}
