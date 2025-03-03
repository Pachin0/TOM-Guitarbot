/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.
 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
hasfhkal;f
#define DEGREEDIFF 20;

#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards
FIR fir(3);

struct SettingS {
  int angleDiff = 0;
  int totalAngle = 0;
  class Servo servo;
};




int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the Servo object
  Serial.begin(9600); // debug crap
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
  float val = 0;
  double output = 0;
  
  while (true) {
    
    val = analogRead(A0);
    val = fir.updateOutput(val);

    




    Serial.println(val);    
    delay(200);
  }

 
}
