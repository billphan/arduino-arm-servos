#include <Wire.h>
#include <Servo.h> 
#include <wiinunchuck.h>
 
Servo panServo; 
Servo tiltServo;
 
int pinPan = 10;
int pinTilt = 11;
 
float panPos = 90.0; // Aktuelle Position
float tiltPos = 90.0; // Aktuelle Position
 
void setup() {
 
 Serial.begin(9600);
 
 nunchuk_init();
 delay(100);
 nunchuk_get_data();
 delay(100); 
 
 panServo.attach(pinPan);
 tiltServo.attach(pinTilt); 
 delay(10);
 panServo.write(panPos);
 tiltServo.write(tiltPos); 
 
}
 
void loop(){
 
 nunchuk_get_data(); // Daten vom Nunchuk empfangen
 delay(10);
 
 
 // Wenn Z-Taste gedrückt dann Bewegung zulassen
 if (nunchuk_zbutton() == 1) {
 // rollangle und pitchangle geben Drehung 
 // um Längs- und Querachse in Grad zurück. Perfekt!
 int roll = nunchuk_rollangle();
 int pitch = nunchuk_pitchangle();
 
 // Nur bis maximale Neigung von 60 Grad berücksichtigen,
 // alles darüber wird ignoriert
 if ((abs(roll) <= 60) & (abs(pitch) <= 60)) {
 // *1.5 um die 60 Grad wieder auf 90 Grad zu mappen
 panPos = 90+roll*1.5;
 tiltPos = 90-pitch*1.5;
 }
 }
 
 char buffer[50];
 // sprintf wird im Video zu Teil 2 erklaert
 sprintf(buffer, "X:%3d Y:%3d Z:%3d - Roll: %3d Pitch: %3d", 
 nunchuk_accelx(), nunchuk_accely(), nunchuk_accelz(), nunchuk_rollangle(), nunchuk_pitchangle());
 Serial.println(buffer);
 
 panServo.write((int)panPos);
 tiltServo.write((int)tiltPos); 
 
 delay(50); 
}
