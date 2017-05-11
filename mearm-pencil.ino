#include <Servo.h> 
 
Servo servoMiddle;
Servo servoLeft;
Servo servoRight;
Servo servoClaw;

void setup() {
  Serial.begin(9600);
  servoMiddle.attach(11);
  servoLeft.attach(10);
  servoRight.attach(9);
  servoClaw.attach(6);
}

void loop() {

  /*
  servoMiddle maximum right turn at 0
  servoMiddle maximum left turn at 180
  servoMiddle center at 90-100
  servoLeft maximum height at 180
  servoLeft maximum depth at 90
  servoRight maximum reach at 180
  servoRight maximum depth at 80
  servoClaw maximum close at 110
  servoClaw maximum open at 25
  */
  
  // starting position
  servoMiddle.write(100);
  servoLeft.write(90);
  servoRight.write(80);
  servoClaw.write(110);
  
  delay(1000);

  // turn right
  servoMiddle.write(140);

  delay(1000);

  // reach for pen
  servoRight.write(120);
  servoLeft.write(100);
  servoClaw.write(50);

  delay(500);

  //grab pen
  servoClaw.write(110);

  delay(500);

  // lift pen
  servoLeft.write(180);
  servoRight.write(90);

  delay(500);

  // turn left
  servoMiddle.write(40);

  delay(1000);

  // open claw, drop pen
  servoClaw.write(50);

  delay(1000);

  // return to starting
  servoMiddle.write(100);
  servoLeft.write(90);
  servoRight.write(80);
  servoClaw.write(110);
  
  delay(1000);

  // head bobbing motion
  servoLeft.write(160);
  delay(250);
  servoLeft.write(100);
  delay(250);
  servoLeft.write(160);
  delay(250);
  servoLeft.write(90);
  delay(250);

  // return to starting
  servoMiddle.write(100);
  servoLeft.write(90);
  servoRight.write(80);
  servoClaw.write(110);

  // stop loop  
  exit(0);
}

