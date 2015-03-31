#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
int moved = 0;
QuadEncoder encoder(2, 3);

int ticks;
int C;
int D;
int E;
int F;
int G;
int A;

const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;
const int Motor2Pin1 = 10;
const int Motor2Pin2 = 11;

void setup() {                
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);  

  Serial.begin(BAUD_RATE);
}

void loop() {
  moved = encoder.tick();
  if (moved == '>' || moved == '<')
  {
    Serial.write("tick!");
  }
}

