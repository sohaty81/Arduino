/* // Tony's Stepper Motor Control with Bluetooth and Pololu Stepper Motor Drivers

#include <AccelStepper.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // i2c pins

// Declare Pins
// const int Pot_Pin = A7;
AccelStepper Motor_1(1, 3, 2);
AccelStepper Motor_2(1, 5, 4);

const int Motor_1_Direction_Pin = 2;
const int Motor_1_Step_Pin = 3;
const int Motor_2_Direction_Pin = 4;
const int Motor_2_Step_Pin = 5;
const int Microstepping_1_Pin = 10;
const int Microstepping_2_Pin = 9;
const int Microstepping_3_Pin = 8;
const int Motor_Enable_Pin = 11;

//Varibles 

int Motor_1_Direction = 0;
int Motor_2_Direction = 0;

// int customDelay = 0;
int customDelayMapped = 0;

int G_Value = 0;
int H_Value = 0;
int I_Value = 0;
int J_Value = 0;

int Motor_1_sign = 1;
int Motor_2_sign = 1;

char BluetoothData; // the data received from bluetooth serial link

// Main Program Setup

void setup() {
 
 lcd.begin(16,2);  //WE define our LCD 16 columns and 2 rows (Char, Line)
 lcd.backlight();  //Power on the back light
 //lcd.backlight(); Power off the back light
  
  // Initialise NANO pins as inputs ot outputs
  
  // pinMode(Pot_Pin, INPUT);
  pinMode(Motor_1_Direction_Pin, OUTPUT);
  pinMode(Motor_1_Step_Pin, OUTPUT);
  pinMode(Motor_2_Direction_Pin, OUTPUT);
  pinMode(Motor_1_Step_Pin, OUTPUT);
  pinMode(Microstepping_1_Pin, OUTPUT);
  pinMode(Microstepping_2_Pin, OUTPUT);
  pinMode(Microstepping_3_Pin, OUTPUT);
  pinMode(Motor_Enable_Pin, OUTPUT);

  Motor_1.setMaxSpeed(4000);
  Motor_1.setAcceleration(100);
  Motor_2.setMaxSpeed(4000);
  Motor_2.setAcceleration(100);

  //initialsie serial communication
  
  Serial.begin(9600);
} // End of Setup

// Main Program Loop

void loop() {
  lcd.clear();//Clean the screen

 // get the speed setting from the poientiometer
  customDelayMapped = speedUp();
 // Process any info coming from the bluetooth serial link
  if (Serial.available()){
    BluetoothData=Serial.read(); //Get next character string from bluetooth
    
     // Serial.print("Bluetooth Data "); Serial.print(BluetoothData); Serial.println();
     lcd.setCursor(0,0);lcd.print("BT-Data"); lcd.setCursor(10,0); lcd.print(BluetoothData);
     // Serial.print("CustomDelayMapped "); Serial.print(customDelayMapped); Serial.println();
     lcd.setCursor(0,1);lcd.print("Pot Reading"); lcd.setCursor(12,1); lcd.print(customDelayMapped);

      if (BluetoothData=='B')  {
       Motor_1.setSpeed(Motor_1_sign * customDelayMapped);
       Motor_1.runSpeed();
      }
       else {
       Motor_1.stop();
      }
      
      if (BluetoothData=='E') {
       Motor_2.setSpeed(Motor_2_sign * customDelayMapped);
       Motor_2.runSpeed();
       }
       else {
       Motor_2.stop();
       }
     
     if(BluetoothData=='A') Motor_1_Direction=Serial.parseInt(); // Motor 1 Direction - 1 is Forward - 0 is reverse
      switch (Motor_1_Direction) {
        case 1: Motor_1_sign = 1;
        break;
        case 0: Motor_1_sign = -1;
        break;
      }
      
     if(BluetoothData=='D') Motor_2_Direction=Serial.parseInt(); // Motor 2 Direction - 1 is Forward - 0 is reverse
      switch (Motor_2_Direction) {
        case 1: Motor_2_sign = 1;
        break;
        case 0: Motor_2_sign = -1;
        break;
      }
       
     if(BluetoothData=='G') G_Value=Serial.parseInt();
       switch(G_Value) {
        case 1: digitalWrite(Motor_Enable_Pin,LOW);  // Motors Enable ON
        break;
        case 0: digitalWrite(Motor_Enable_Pin,HIGH); // Motors Enable OFF
        break;
      }
      
    if(BluetoothData=='H') H_Value=Serial.parseInt();// Microstepping 1 ON / OFF
      switch(H_Value) {
        case 1: digitalWrite(Microstepping_1_Pin,HIGH); 
        break;
        case 0: digitalWrite(Microstepping_1_Pin,LOW);
        break;
      }
      
    if(BluetoothData=='I') I_Value=Serial.parseInt();// Microstepping 2 On / OFF
      switch(I_Value) {
        case 1: digitalWrite(Microstepping_2_Pin,HIGH);
        break;

        case 0: digitalWrite(Microstepping_2_Pin,LOW);
        break;
      }
       
      if(BluetoothData=='J') J_Value=Serial.parseInt();// Microstepping 3 On / OFF
       switch(J_Value) {
        case 1: digitalWrite(Microstepping_3_Pin,HIGH);
        break;

        case 0: digitalWrite(Microstepping_3_Pin,LOW);
        break;
      }
    } 
  }

// End of Main Program

// Routine to read and map the potentiometer
int speedUp() {
  int customDelay = analogRead(A0);
  int newCustom = map(customDelay, 0, 1023, 300, 4000);
  return newCustom;
}

  

 */