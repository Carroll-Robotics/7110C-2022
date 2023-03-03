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

#include <iostream>
#include <string>
#include "string.h"
#include "math.h"
#include "vex.h"

using namespace vex;

competition Competition;

//measure and enter width and length and wheel diameter
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
  sensor.calibrate();
  while (sensor.isCalibrating()) {
    wait(100, msec);
  }
}
/*
void turnTo(float deg) {
  FrontLeft.spin(forward);
  FrontRight.spin(reverse);
  BackLeft.spin(forward);
  BackRight.spin(reverse);
  if(deg<sensor.heading()) {
    waitUntil(sensor.heading()>=deg);
  }
  else if(deg>sensor.heading()) {
    waitUntil(sensor.heading()<=deg);
  }
  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();
  
}*/

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
void rollers(void) {
  roller(2.75);
  simpleDrive(reverse, 16, true);
  driveTurn(90);
  roller(22);
  simpleDrive(reverse,48,true);
  driveTurn(-90);
  simpleDrive(reverse,78,true);
  driveTurn(-90);
  simpleDrive(forward,28,true);
  roller(20);
  driveTurn(-90);
  roller(24);
}

void turnTo(float deg) {
  if(deg>sensor.heading(degrees))
    while(sensor.heading(degrees) < deg) {
      FrontLeft.spin(forward);
      FrontRight.spin(reverse);
      BackLeft.spin(forward);
      BackRight.spin(reverse);
  } else {
    while(sensor.heading(degrees) > deg) {
      FrontLeft.spin(reverse);
      FrontRight.spin(forward);
      BackLeft.spin(reverse);
      BackRight.spin(forward);
    }
  }
  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();

}
bool spinUp(float speed) {
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
void shoot() {
  Indexer.set(true);
  wait(50,msec);
  Indexer.set(false);
  fireReady=false;
}
void driveStraight(directionType dir, float dist) {
  float ke = 0.35;
  float kd = 0.25;
  float ki = 0.10;
  int eRec = 0;
  int e = 0;
  int d = 0;
  int i = 0;
  int rightVelocity = 100;
  int leftVelocity = 100;
  FrontRight.resetPosition();
  float degAmt = dist/wheelCirc * 360;
  while (FrontRight.position(degrees) <= degAmt) {
    //int heading = sensor.heading();
    e = FrontRight.velocity(rpm) - FrontLeft.velocity(rpm);
    d = e - eRec;
    i += e;
    eRec = e;
    leftVelocity = rightVelocity + 100 * (ke * e + kd * d + ki * i);
    if(i>20000) i=20000;
    if(i<-20000) i=-20000;
    if(leftVelocity>200) leftVelocity=200;
    if(leftVelocity<0) leftVelocity=0;
    FrontRight.spin(dir, rightVelocity, rpm);
    BackRight.spin(dir, rightVelocity, rpm);
    FrontLeft.spin(dir, leftVelocity, rpm);
    BackLeft.spin(dir, leftVelocity, rpm);
    wait(250, msec);
    Controller1.Screen.print("%d, %d, %d, %d", e, d, i, leftVelocity);
    Controller1.Screen.newLine();
  }
  FrontRight.stop();
  FrontLeft.stop();
  BackRight.stop();
  BackLeft.stop();
}
void expansion() {
  Expansion.spin(fwd, 100, pct);
  wait(1, sec);
  Expansion.stop();
}

void autonomous(void) {
  // insert code
  //rollers();
  roller(2.75);
  driveTurn(150);
  Intake_Roller.spin(fwd);
  simpleDrive(fwd, 12, true);
  Intake_Roller.stop();
  simpleDrive(reverse,12,true);
  driveTurn(-63.5);
  spinUp(450);
  waitUntil(fireReady);
  shoot();
/*
  simpleDrive(forward, 24, true);
  turnTo(90);
  simpleDrive(forward, 24, true);
  turnTo(180);
  simpleDrive(forward, 24, true);
  turnTo(270);
  simpleDrive(forward, 24, true);
  */
  /*turnTo(90);
  waitUntil(!FrontLeft.isSpinning());
  driveTurn(-90);
  driveTurn(180);*/

  /*bool ready = spinUp(500);
  waitUntil(ready);
  shoot();
  wait(250,msec);
  shoot();
  wait(250,msec);
  shoot();*/
  /*
  int deadband = 5;
  bool intakeMode = true;
  Indexer.set(false);
  bool wasPressing = false;
  int LauncherSpeed=350;
  bool fireReady = false;
  roller(2.75);
  simpleDrive(reverse, 6, true);
  driveTurn(90);
  Intake_Roller.spin(fwd, 200, rpm);
  simpleDrive(forward, 7, false);
  wait(2.5, sec);
  Intake_Roller.stop();
  roller(1.5);
  simpleDrive(reverse, 22, true);
  Launcher1.spin(forward, 335, rpm);
  Launcher2.spin(forward, 335, rpm);
  driveTurn(10);
  fireReady = spinUp(335);
  waitUntil(fireReady);
  shoot();
  wait(0.5, sec);
  shoot();
  wait(0.5, sec);
  shoot();
  Launcher1.stop();
  Launcher2.stop();
  fireReady=false;
  turnTo(180);
  simpleDrive(forward, 16, true);
  driveTurn(45);
  Intake_Roller.spin(forward, 200, rpm);
  simpleDrive(forward, 18.5, false);
  wait(3,sec);
  Intake_Roller.stop();
  wait(3,sec);
  driveTurn(-47.5);
  fireReady = spinUp(450);
  waitUntil(fireReady);
  shoot();
  wait(0.5, sec);
  shoot();
  wait(0.5, sec);
  shoot();
  Launcher1.stop();
  Launcher2.stop();
  fireReady=false;
  driveTurn(105);
  Intake_Roller.spin(forward, 200, rpm);
  simpleDrive(forward, 8, false);
  wait(2, sec);
  Intake_Roller.stop();
  roller(3);
  simpleDrive(reverse, 6.5, true);
  driveTurn(-90);

  roller(8);
  driveTurn(25);
  expansion();
*/




}
/*
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
  //  LauncherSpeed += 50;
}

void whenControllerR2Pressed() {
  //  LauncherSpeed -= 50;
}
void whenControllerButtonAPressed() {
  //  LauncherSpeed = 0;
}
void expansion() {
  waitUntil(Controller1.ButtonX.pressing());
  // Expansion.set(false);
}
*/
void usercontrol(void) { vexcodeInit(); }

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
