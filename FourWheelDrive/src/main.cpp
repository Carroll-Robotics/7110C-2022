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
  //Piston.set(true);
  //vexcodeInit();
}

void autonomous(void) {
  //insert code
  FrontRight.rotateFor(directionType::rev, 720, rotationUnits::deg, 50, velocityUnits::pct, false);
  FrontLeft.rotateFor(directionType::rev, 720, rotationUnits::deg, 50, velocityUnits::pct, true);
  FrontRight.rotateFor(directionType::rev, 540, rotationUnits::deg, 50, velocityUnits::pct, true);
  Roller.rotateFor(directionType::rev, 95, rotationUnits::deg, 80, velocityUnits::pct, false);
  Roller.rotateFor(directionType::fwd, 40, rotationUnits::deg, 50, velocityUnits::pct, false);

}

int LauncherSpeed = 350;
void whenControllerL1Pressed() {
  Roller.spin(forward);
  Intake.spin(forward);
  waitUntil(!Controller1.ButtonL1.pressing());
  Roller.stop();
  Intake.stop();
}

void whenControllerL2Pressed() {
  Roller.spin(reverse);
  Intake.spin(reverse);
  waitUntil(!Controller1.ButtonL2.pressing());
  Roller.stop();
  Intake.stop();
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

void krishistrashatcoding() {
  Piston.set(false);
}
void expansion() {
  waitUntil(Controller1.ButtonX.pressing());
  Piston.set(true);
}
/*
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
      Intake.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      Intake.spin(reverse);
    } else {
      Intake.stop();
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
*/
int main() {
  Piston.set(true);
  vexcodeInit();
  int deadband = 5;
  Launcher1.setVelocity(0, rpm);
  Launcher2.setVelocity(0, rpm);
  Controller1.ButtonX.pressed(krishistrashatcoding);
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
    /*if(Controller1.ButtonX.pressing()) {
      //Piston.set(false);
      expansion();
    }*/ 
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
