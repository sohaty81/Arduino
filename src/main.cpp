#include <Arduino.h>
#include <AccelStepper.h>

boolean trigger_forward = false ;
boolean trigger_backward = false ;

const long distance = 1000; //distance of the stepper

int leBigMove = 20000;
int commande = 0; 

int led = 13;
int limSwitch = 9;
int motor1DirPin = 2; //digital pin 2   
int motor1StepPin = 5; //digital pin 3

//AccelStepper stepper1(1,7,8); 

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::FULL4WIRE, 2, 4,3, 5);; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

// put function declarations here:
//int myFunction(int, int);
void driverFunction();
void exposeRA();
void hideRA();


void setup() {

  pinMode(led, OUTPUT);
  pinMode (limSwitch, INPUT);
  
 /*  stepper.setMaxSpeed(100);
  stepper.setAcceleration(20);
  stepper.moveTo(500); */

     //stepper.setMaxSpeed(1000);
     //stepper.setSpeed(350);

    stepper.setMaxSpeed(1000);
    //stepper.setSpeed(200);
    stepper.setAcceleration(100.0);
    
    //stepper.moveTo(2000);
  //stepper.move(distance);
trigger_forward = true ;
stepper.enableOutputs();
}

void loop() {









    // If at the end of travel go to the other end
   /*  if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run(); */
    //stepper.runSpeed();

 //driverFunction();

//exposeRA(); //run the stepper forward
//<--------I think right here is where I need to be able to wait a certain amount of time for examp 30 seconds

//delay(1000);

//hideRA(); //run the stepper backward
//<-------now repeat

//stepper.moveTo(-500);
//stepper.run();
//delay(1000);
//stepper.setSpeed(-200);
//stepper.moveTo(-300);
//trigger_forward = false;
//trigger_backward = true;
//stepper.setSpeed(200);
//delay(1000);
//stepper.runToPosition();
//stepper.setCurrentPosition(-200);
//stepper.runSpeedToPosition();
//stepper.move(100);
//delay(1000);
//stepper.runToPosition();
//stepper.setCurrentPosition(200);



/* if (stepper.distanceToGo () == 0) {
        stepper.moveTo(-1700);
    }
    stepper.runToPosition();
} */




void exposeRA()
{
stepper.setSpeed(-200);
stepper.run();
stepper.moveTo(300);
//stepper.moveTo(stepper.currentPosition() + distance);
stepper.stop();
}

void hideRA()
{
stepper.setSpeed(200);
stepper.run();
stepper.moveTo(300);
//stepper.moveTo(stepper.currentPosition() - distance);
stepper.stop();
}






void driverFunction() {
    stepper.runToNewPosition(0);
    stepper.runToNewPosition(500);
    stepper.runToNewPosition(50);
    stepper.runToNewPosition(200);
    stepper.runToNewPosition(10);
    
    stepper.runToNewPosition(0);
}

// put function definitions here:
// int myFunction(int x, int y) {
 // return x + y;
//} 