/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.
	fdsa;flkdsafjd;slkfjs;lsakfj
 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#define DEGREEDIFF 20;

#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

struct SettingS {
  int angleDiff = 0;
  int totalAngle = 0;
  class Servo servo;
};




int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the Servo object
}



int globalpos = 70;

void pluck(Servo servo){
  if (globalpos <= 70) {
    servo.write(200);
    globalpos = 200;

  } else {
    servo.write(70);
    globalpos = 70;
  }
}




void loop() {
  struct SettingS a;
  a.angleDiff = DEGREEDIFF;
  
  while true {
    


  }

 
}
