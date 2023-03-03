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

float wheelRadius = 3.25/2;
float width = 16.3386;
float length = 0;
float robotRadius = sqrt(width*width + length*length)/2;
float wheelCirc = wheelRadius * 2 * M_PI;
float gr = 0.6;
double Kr = 0.8721445746*1.054572148;
bool fireReady = false;

void pre_auton(void) {
  vexcodeInit();
}
void driveTurn(float deg) {
  float dist = Kr * gr * deg * robotRadius / wheelRadius;
  FrontLeft.rotateFor(fwd, dist, vex::deg, false);
  BackLeft.rotateFor(fwd, dist, vex::deg, false);
  FrontRight.rotateFor(reverse, dist, vex::deg, false);
  BackRight.rotateFor(reverse, dist, vex::deg, true);
}


void simpleDrive(directionType dir, float dist, bool stop) {
  float degAmt = dist/wheelCirc * 360 * gr;
  FrontLeft.rotateFor(dir, degAmt,  deg, false);
  FrontRight.rotateFor(dir, degAmt, deg, false);
  BackLeft.rotateFor(dir, degAmt, deg, false);
  BackRight.rotateFor(dir, degAmt, deg, stop);
}
void roller(float dist) {
  simpleDrive(forward, dist, false);
  wait(0.75*dist/3, sec);
  Intake_Roller.rotateFor(directionType::rev, 200, rotationUnits::deg, 100, velocityUnits::pct, false);
  wait(0.5,sec);
  simpleDrive(reverse, dist, true);
}
void spinUp(float speed) {
  wait(0.15,sec);
  if(Launcher1.velocity(rpm)==0) return;
  float eRec = 0;
  float dRec = 0;
  float ddRec = 0;
  float e = speed - Launcher1.velocity(rpm);
  float d = e-eRec;
  float dd = d-dRec;
  float ddd = dd-ddRec;
  float kp = 0.85;
  float kd = 0.25;
  float kdd = 0.15;
  float kddd = 0.05;
  eRec=e;
  dRec=d;
  ddRec=dd;

  while(kp*e + kd*d + kdd*dd + kddd*ddd > 20) {
    e = speed - Launcher1.velocity(rpm);
    d = e-eRec;
    dd = d-dRec;
    ddd = dd-ddRec;
    eRec=e;
    dRec=d;
    ddRec=dd;
    wait(25,msec);
  }
  Controller1.rumble("-");
}
void shoot() {
  Indexer.set(true);
  wait(50,msec);
  Indexer.set(false);
  fireReady=false;
}
bool spinUpAuton(float speed) {
  Launcher1.spin(forward, speed, rpm);
  Launcher2.spin(forward, speed, rpm);
  float eRec = 0;
  float dRec = 0;
  float ddRec = 0;
  float e = speed - Launcher1.velocity(rpm);
  float d = e-eRec;
  float dd = d-dRec;
  float ddd = dd-ddRec;
  float kp = 0.85;
  float kd = 0.25;
  float kdd = 0.15;
  float kddd = 0.05;
  eRec=e;
  dRec=d;
  ddRec=dd;

  while(kp*e + kd*d + kdd*dd + kddd*ddd > 30) {
    e = speed - Launcher1.velocity(rpm);
    d = e-eRec;
    dd = d-dRec;
    ddd = dd-ddRec;
    eRec=e;
    dRec=d;
    ddRec=dd;
  }
  return fireReady=true;
}
void expansion() {
  waitUntil(Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing());
  Expansion.set(true);
}

void autonomous(void) {
  //insert code
  simpleDrive(reverse,20,true);
  driveTurn(90);
  roller(6);
  driveTurn(3.366);
  spinUpAuton(450);
  waitUntil(fireReady);
  shoot();
  spinUpAuton(450);
  waitUntil(fireReady);
  shoot();
  Launcher1.stop();
  Launcher2.stop();
}


void usercontrol(void) {
  int deadband = 5;
  bool intakeMode = true;
  float driveLimit = 0.8;
  Launcher1.setVelocity(0, rpm);
  Launcher2.setVelocity(0, rpm);
  Controller1.ButtonX.pressed(expansion);
  bool wasPressing = false;
  float ke = 0.35;
  float kd = 0.65;
  float ki = 0.0;
  int eRec = 0;
  int e = 0;
  int d = 0;
  int i = 0;
  int launcherSpeed = 325;
  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = intakeMode ? Controller1.Axis3.position() : (-1*Controller1.Axis2.position());
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = intakeMode ? Controller1.Axis2.position() : (-1*Controller1.Axis3.position());
    /*if(Launcher1.velocity(rpm)!=0) {
      e = Launcher1.velocity(rpm)-350;
      d = e-eRec;
      i+=e;
      eRec=e;
      launcherSpeed = 350 - 150*(ki*i + ke*e + kd*d);
    }*/
    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      FrontLeft.setVelocity(0, percent);
      BackLeft.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      FrontLeft.setVelocity(driveLimit * leftMotorSpeed, percent);
      BackLeft.setVelocity(driveLimit * leftMotorSpeed, percent);
    }
    if (Controller1.ButtonUp.pressing()) {
      intakeMode = true;
    } else if (Controller1.ButtonDown.pressing()) {
      intakeMode = false;
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      FrontRight.setVelocity(0, percent);
      BackRight.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      FrontRight.setVelocity(driveLimit * rightMotorSpeed, percent);
      BackRight.setVelocity(driveLimit * rightMotorSpeed, percent);
    }
    if (Controller1.ButtonL1.pressing()) {
      Intake_Roller.spin(forward);
    } else if (Controller1.ButtonL2.pressing()) {
      Intake_Roller.spin(reverse);
    } else {
      Intake_Roller.stop();
    }
    if(Controller1.ButtonY.pressing() && !wasPressing) {
      Indexer.set(true);
      wait(50,msec);
      Indexer.set(false);
      spinUp(launcherSpeed);
    }
    wasPressing = (Controller1.ButtonY.pressing());
    /*if(Controller1.ButtonX.pressing()) {
      //Piston.set(false);
      expansion();
    }*/ 
    if(Controller1.ButtonA.pressing()) {
      Launcher1.setVelocity(launcherSpeed, rpm);
      Launcher2.setVelocity(launcherSpeed, rpm);
      spinUp(launcherSpeed);
    }
    if(Controller1.ButtonB.pressing()) {
      Launcher1.setVelocity(0, rpm);
      Launcher2.setVelocity(0, rpm);
      //launcherSpeed=350;
    }
    // Spin both motors in the forward direction.
    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    BackLeft.spin(forward);
    BackRight.spin(forward);
    Launcher1.spin(forward);
    Launcher2.spin(forward);
    Controller1.Screen.print(Launcher1.velocity(rpm) - 350);
    Controller1.Screen.newLine();

    wait(25, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
