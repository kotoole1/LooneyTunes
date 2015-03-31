#include <TimerThree.h>

//#include <QuadEncoder.h>
//
//int moved = 0;
//QuadEncoder encoder(30, 32);

// pin numbers
int motor1 = 2;
int motor2 = 3;
int pot = A0;
int loopCount = 0;

void setup() {
    Serial.begin(9600);
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    for (int i=22; i<=53; i++) {
      pinMode(i, INPUT);
    }
    fullForward();
    
    Timer3.attachInterrupt(sendAnalogValue, 10000);
    
    Serial.print("start\n");
}

void sendAnalogValue() {
  int potValue = analogRead(pot);
  Serial.println(potValue);
}

void fullForward() {
  analogWrite(2, 255);
  analogWrite(3, 0);
}

void loop() {

}

