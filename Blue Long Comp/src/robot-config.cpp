#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FrontRight = motor(PORT12, ratio18_1, true);
motor FrontLeft = motor(PORT10, ratio18_1, false);
motor LowerIntake = motor(PORT8, ratio18_1, false);
motor UpperIntake = motor(PORT6, ratio18_1, false);
motor Launcher1 = motor(PORT3, ratio6_1, true);
motor Launcher2 = motor(PORT4, ratio6_1, true);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // nothing to initialize
}