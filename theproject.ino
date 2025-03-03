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
  //myservo.attach(9);   // attaches the servo on pin 9 to the Servo object
  Serial.begin(9600);  // debug crap
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

bool edge(bool last, bool initial) {
  if (initial != last) {
    Serial.println("nigga");
    return initial;
  }
  return last;
  }

SchmittTrigger<int> trigger1(100, 200);
SchmittTrigger<int> trigger2(200, 300);
SchmittTrigger<int> trigger3(300, 400);
SchmittTrigger<int> trigger4(500, 600);
SchmittTrigger<int> trigger5(600, 700);
SchmittTrigger<int> trigger6(800, 900);



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
  bool last = 0;

  while (true) {

    val = analogRead(A0);
    val = fir.updateOutput(val);

    trigger1.input(val);
    trigger2.input(val);
    trigger3.input(val);
    trigger4.input(val);
    trigger5.input(val);
    trigger6.input(val);


    digitalWrite(11, trigger1.output());
    digitalWrite(10, trigger2.output());
    digitalWrite(9, trigger3.output());
    last = edge(last, trigger4.output());
    digitalWrite(5, trigger5.output());
    digitalWrite(3, trigger6.output());

    Serial.println(val);
    delay(150);
  }
}
