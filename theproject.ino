#include <FIR.h>
#define DEGREEDIFF 20;
#include <SchmittTrigger.h>
#include <Servo.h>



Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards
FIR fir(3);

struct SettingS {
  int angleDiff = 0;
  int totalAngle = 0;
  class Servo servo;
};




int pos = 0;  // variable to store the servo position

void setup() {
  myservo.attach(9);   // attaches the servo on pin 9 to the Servo object
  Serial.begin(9600);  // debug crap
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
SchmittTrigger<int> trigger1(100, 200);
SchmittTrigger<int> trigger2(300, 400);
SchmittTrigger<int> trigger3(500, 600);
SchmittTrigger<int> trigger4(600, 700);




int globalpos = 70;

void pluck(Servo servo) {
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

    trigger1.input(val);
    trigger2.input(val);
    trigger3.input(val);
    trigger4.input(val);


    digitalWrite(11, trigger1.output());
    digitalWrite(10, trigger2.output());
    digitalWrite(9, trigger3.output());
    digitalWrite(6, trigger4.output());   


    Serial.println(val);
    delay(200);
  }
}
