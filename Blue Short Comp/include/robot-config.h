using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FrontLeft;
extern motor FrontRight;
extern motor LowerIntake;
extern motor UpperIntake;
extern motor Launcher1;
extern motor Launcher2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);