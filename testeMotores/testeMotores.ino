/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;
Servo j1;
Servo j2;
Servo j3;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(6);
  j1.attach(7);
  j2.attach(8);
  j3.attach(9);
  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 90; pos <= 170; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    j1.write(pos);
    delay(15);
    j2.write(pos);
    delay(15);
    j3.write(pos);
    delay(15);
  }
  for (pos = 170; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    j1.write(pos);
    delay(15);
    j2.write(pos);
    delay(15);
    j3.write(pos);
    delay(15);
  }
}
