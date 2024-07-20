#include <AccelStepper.h>
#include <ESP32Servo.h>

//Engine 1
#define STEP_PIN_1 2
#define DIR_PIN_1 14
#define ENDSTOP_PIN_1 15

//Engine 2
#define STEP_PIN_2 18
#define DIR_PIN_2 19
#define ENDSTOP_PIN_2 5

//Engine 3
#define STEP_PIN_3 4
#define DIR_PIN_3 16
#define ENDSTOP_PIN_3 17

//Servo def
#define SERVO_PIN 21

//Engine def
AccelStepper stepper1(AccelStepper::DRIVER, STEP_PIN_1, DIR_PIN_1);
AccelStepper stepper2(AccelStepper::DRIVER, STEP_PIN_2, DIR_PIN_2);
AccelStepper stepper3(AccelStepper::DRIVER, STEP_PIN_3, DIR_PIN_3);


Servo servo;

void setup() {
  Serial.begin(9600);

  //Engine speed def
  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(400);
  stepper2.setMaxSpeed(200);
  stepper2.setAcceleration(400);
  stepper3.setMaxSpeed(200);
  stepper3.setAcceleration(400);

  //Endstop pins input
  pinMode(ENDSTOP_PIN_1, INPUT_PULLUP);
  pinMode(ENDSTOP_PIN_2, INPUT_PULLUP);
  pinMode(ENDSTOP_PIN_3, INPUT_PULLUP);

  servo.attach(SERVO_PIN); 
  servo.write(180); 
}

void homing(AccelStepper &stepper, int endstopPin, bool direction) {
  stepper.setSpeed(direction ? 200 : -200); 
  while (digitalRead(endstopPin) == HIGH) {
    stepper.runSpeed();
  }
  stepper.setCurrentPosition(0);
}

void moveToPosition(AccelStepper &stepper, int steps, int speed) {
  stepper.setSpeed(speed);
  stepper.move(steps);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
}

void moveServo(int angle) {
  servo.write(angle); 
  delay(500); 
}

void loop() {
  //Engine homing
  homing(stepper1, ENDSTOP_PIN_1, true);
  delay(200);

  homing(stepper2, ENDSTOP_PIN_2, false);
  delay(200);

  homing(stepper3, ENDSTOP_PIN_3, true);
  delay(200);


  //Engine first position
  moveToPosition(stepper1, 100, 250);
  delay(200);
  
  moveToPosition(stepper2, -150, 250);
  delay(200);
  
  moveToPosition(stepper3, 200, 250);
  delay(200);


  //Engine movement
  moveToPosition(stepper1, 100, 250);
  delay(200);

  moveToPosition(stepper2, -150, 250);
  delay(200);

  moveToPosition(stepper3, 200, 250);
  delay(200);

  moveServo(100); 
  delay(200); 

  moveToPosition(stepper1, -130, 250); 
  delay(200);

  moveToPosition(stepper2, 210, 250); 
  delay(200);

  moveToPosition(stepper3, -250, 250); 
  delay(200);

  moveServo(160); 
  delay(200); 

  moveToPosition(stepper1, 100, 250); 
  delay(200);

  moveToPosition(stepper2, -150, 250); 
  delay(200);

  moveToPosition(stepper3, 120, 250);
  delay(200);

  moveServo(90); 

  //Enigne stop
  while (true) {
    stepper1.stop();
    stepper2.stop();
    stepper3.stop();
  }
}
