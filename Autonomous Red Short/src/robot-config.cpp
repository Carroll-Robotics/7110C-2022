#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

motor FrontLeft = motor(PORT12, ratio18_1, true);
motor FrontRight = motor(PORT10, ratio18_1, false);
motor LowerIntake = motor(PORT8, ratio18_1, false);
motor UpperIntake = motor(PORT6, ratio18_1, false);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}