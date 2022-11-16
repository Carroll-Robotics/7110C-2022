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
// LeftMotor            motor         1
// RightMotor           motor         10
// ClawMotor            motor         3
// ArmMotor             motor         8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
int LauncherSpeed = 0;
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
  LauncherSpeed += 10;
}

void whenControllerR2Pressed() {
  LauncherSpeed -= 10;
}
void whenControllerAPressed() {
  LauncherSpeed = 0;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();
    Launcher1.setVelocity(350, rpm);
    Launcher2.setVelocity(350, rpm);
    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      LeftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      RightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      RightMotor.setVelocity(rightMotorSpeed, percent);
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
    LeftMotor.spin(forward);
    RightMotor.spin(forward);
    Launcher1.spin(forward);
    Launcher2.spin(forward);

    wait(25, msec);
    
  }
}
