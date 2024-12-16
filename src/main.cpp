#include <GyverStepper.h>

//AccelStepper stepper1(1,7,8); 

// Define a stepper and the pins it will use
GStepper<STEPPER4WIRE> stepper(2048, 5, 3, 4, 2);

// put function declarations here:
//int myFunction(int, int);
//void driverFunction();



void setup() {
 Serial.begin(115200);
  // режим следования к целевй позиции
  stepper.setRunMode(FOLLOW_POS);
  // установка макс. скорости в шагах/сек
  stepper.setMaxSpeed(400);
  // установка ускорения в шагах/сек/сек
  stepper.setAcceleration(500);
}

void loop() {



  // просто крутим туды-сюды
/*   if (!stepper.tick()) {
    static bool dir;
    dir = !dir;
    stepper.setTarget(dir ? -400 : 400);
  }
 */

//int cur = stepper.getCurrentDeg();
//stepper.setTargetDeg(90);
if (!stepper.tick()) {

    //stepper.reverse(false);
    stepper.setTargetDeg(145);

    if (stepper.getCurrentDeg() == 90) {
      stepper.stop();
    }
    
    //stepper.reverse(true);
    if (!stepper.tick()) {
      stepper.setTargetDeg(-145);
    }

//stepper.setCurrentDeg(0);
/*   if (stepper.getCurrentDeg() == -45) {
    //stepper.autoPower(true);
    stepper.reverse(false);
    stepper.setTargetDeg(45);

    stepper.reverse(true);
    stepper.setTargetDeg(45);
    //stepper.disable();
    //stepper.setTargetDeg(-45);
  //} else {
    //stepper.setTargetDeg(45);
  } */
}




  // график положения
/*   static uint32_t tmr2;
  if (millis() - tmr2 > 20) {
    tmr2 = millis();
    Serial.println(stepper.getCurrent());
  } */

}








/* void driverFunction() {
  int x =5;
} */

// put function definitions here:
// int myFunction(int x, int y) {
 // return x + y;
//} 