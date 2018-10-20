#include <Stepper.h>
#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
Stepper stepper(STEPS, 8, 10, 9, 11);
void setup() {
  // nothing to do
}
void loop() {
  stepper.setSpeed(17); // 1 rpm
  stepper.step(550); // do 2038 steps -- corresponds to one revolution in one minute
  delay(100); // wait for one second
  stepper.setSpeed(17); // 6 rpm
  stepper.step(-550); // do 2038 steps in the other direction with faster speed -- corresponds to one revolution in 10 seconds
}
