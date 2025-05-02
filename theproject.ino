#include <FIR.h>
#define DEGREEDIFF 20;
#define DEGREE1 70
#define DEGREE2 100
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
  class Servo thething;
};


void handleState(struct state* mystate, bool current) {
  mystate->last = edge(mystate->last, current, mystate);
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
  int initial1 = info->pos1;
  int initial2 = info->pos2;
  info->pos1 = initial2;
  info->pos2 = initial1;
}

bool edge(bool last, bool initial, struct state* info) {
  //Serial.println(digitalRead(12));
  if (initial != last) {
    if (digitalRead(12)) {
      servoAngle(info);      
      info->thething.write(info->pos1);
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

  //s1.pin = 11;
  s1.thething.attach(11); //A
  s1.pos1 = 60;
  s1.pos2 = 90;
  //s2.pin = 10;
  s2.thething.attach(10); //G
  s2.pos1 = 65;
  s2.pos2 = 95;
  //s3.pin = 9;
  s3.thething.attach(9); //HIGH E
  s3.pos1 = 70;
  s3.pos2 = 100;
  //s4.pin = 6;
  s4.thething.attach(6); //B
  s4.pos1 = 70;
  s4.pos2 = 110;
  //s5.pin = 5;
  s5.thething.attach(5); //D
  s5.pos1 = 70;
  s5.pos2 = 100;
  //s6.pin = 3;
  s6.thething.attach(3); //LOW E
  s6.pos1 = 70;
  s6.pos2 = 92;

  while (true) {

    val = analogRead(A0);
    val = fir.updateOutput(val);

    //val = (val - 300) * 1.999;

    Serial.println(val);
    trigger1.input(val);
    trigger2.input(val);
    trigger3.input(val);
    trigger4.input(val);
    trigger5.input(val);
    trigger6.input(val);
    Serial.println(val);


    handleState(&s6, trigger1.output());
    handleState(&s1, trigger2.output());
    handleState(&s5, trigger3.output());
    handleState(&s2, trigger4.output());
    handleState(&s4, trigger5.output());
    handleState(&s3, trigger6.output());
    delay(10);
  }
}
