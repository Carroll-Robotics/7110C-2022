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

/*competition Competition;

void pre_auton(void) {
  
  vexcodeInit();

}

void autonomous(void) {
  //insert code
  FrontRight.rotateFor(directionType::fwd, 720, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 720, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontLeft.rotateFor(directionType::fwd, 180, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontRight.rotateFor(directionType::rev, 360, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::fwd, 540, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 600, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontLeft.rotateFor(directionType::fwd, 100, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontRight.rotateFor(directionType::rev, 100, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::fwd, 180, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 180, rotationUnits::deg, 50, velocityUnits::pct, true);
  Roller.rotateFor(directionType::rev, 80, rotationUnits::deg, 100, velocityUnits::pct, false);

}

int LauncherSpeed = 350;
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
  Launcher1.setVelocity(0, rpm);
  Launcher2.setVelocity(0, rpm);
  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = Controller1.Axis2.position();
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = Controller1.Axis3.position();
    
    Intake.setVelocity(150, rpm);
    Roller.setVelocity(175,rpm);
    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      FrontLeft.setVelocity(0, percent);
      BackLeft.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      FrontLeft.setVelocity(leftMotorSpeed, percent);
      BackLeft.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      FrontRight.setVelocity(0, percent);
      BackRight.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      FrontRight.setVelocity(rightMotorSpeed, percent);
      BackRight.setVelocity(rightMotorSpeed, percent);
    }
    if (Controller1.ButtonR1.pressing()) {
      Roller.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      Roller.spin(reverse);
    } else {
      Roller.stop();
    }
    if (Controller1.ButtonL1.pressing()) {
      Intake.spin(forward);
    } else if (Controller1.ButtonL2.pressing()) {
      Intake.spin(reverse);
    } else {
      Intake.stop();
    }
    if(!Controller1.ButtonX.pressing()) {
      Piston.set(true);
    } else {
      Piston.set(false);
    }
    if(Controller1.ButtonA.pressing()) {
      Launcher1.setVelocity(350, rpm);
      Launcher2.setVelocity(350, rpm);
    }
    if(Controller1.ButtonB.pressing()) {
      Launcher1.setVelocity(0, rpm);
      Launcher2.setVelocity(0, rpm);
    }
    // Spin both motors in the forward direction.
    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    BackLeft.spin(forward);
    BackRight.spin(forward);
    Launcher1.spin(forward);
    Launcher2.spin(forward);

    wait(25, msec);
  }
}
*/int main() {
  /*Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while(true) {
    wait(100, msec);
  }*/
  vexcodeInit();
  FrontRight.rotateFor(directionType::rev, 720, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 720, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontLeft.rotateFor(directionType::fwd, 180, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontRight.rotateFor(directionType::rev, 360, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::rev, 540, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 600, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontLeft.rotateFor(directionType::fwd, 100, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontRight.rotateFor(directionType::rev, 100, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::rev, 240, rotationUnits::deg, 50, velocityUnits::pct, false);
  BackRight.rotateFor(directionType::rev, 240, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 180, rotationUnits::deg, 50, velocityUnits::pct, true);
  Roller.rotateFor(directionType::rev, 80, rotationUnits::deg, 100, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::fwd, 100, rotationUnits::deg, false);
  BackLeft.rotateFor(directionType::fwd, 100, rotationUnits::deg, true);
  Intake.setVelocity(200, rpm);
  Launcher1.setVelocity(370, rpm);
  Launcher2.setVelocity(370,rpm);
  Launcher1.spin(forward);
  Launcher2.spin(forward);
  wait(3.5, seconds);
  Intake.spin(forward);
  wait(1.5, seconds);
  Intake.stop();
  Launcher1.stop();
  Launcher2.stop();
}
