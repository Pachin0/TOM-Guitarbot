#include <FIR.h>
#define DEGREEDIFF 20;
#include <SchmittTrigger.h>
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards
FIR fir(3);

struct state {
  int pin;
  int pos1;
  int pos2;
  int totalAngle;
  bool last;
  class Servo servo;
};

void handleState(struct state* mystate, bool current) {
  mystate->last = edge(mystate->last, current, mystate->pin);
}


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
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void servoAngle (struct state* info) {
  info->pos1
  info->pos2
  

}

bool edge(bool last, bool initial, struct state* info) {
  if (initial != last) {
    if (digitalRead(4)) {
        Serial.print("LED PIN");
        Serial.println(pin);

        digitalWrite(pin, HIGH);
        delay(50);
        digitalWrite(pin, LOW);
    }

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

void pluck() {
}

void loop() {
  struct state s1 = { 0 };
  struct state s2 = { 0 };
  struct state s3 = { 0 };
  struct state s4 = { 0 };
  struct state s5 = { 0 };
  struct state s6 = { 0 };

  float val = 0;
  double output = 0;
  bool last = 0;

  s1.pin = 11;
  s2.pin = 10;
  s3.pin = 9;
  s4.pin = 6;
  s5.pin = 5;
  s6.pin = 3;

  while (true) {

    val = analogRead(A0);
    val = fir.updateOutput(val);

    trigger1.input(val);
    trigger2.input(val);
    trigger3.input(val);
    trigger4.input(val);
    trigger5.input(val);
    trigger6.input(val);


    handleState(&s1, trigger1.output());
    handleState(&s2, trigger2.output());
    handleState(&s3, trigger3.output());
    handleState(&s4, trigger4.output());
    handleState(&s5, trigger5.output());
    handleState(&s6, trigger6.output());

    Serial.println(val);
    delay(10);
  }
}
