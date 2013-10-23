#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
int moved = 0;
Quadencoder encoder(2, 3);

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
    HaltAndCatchFire();
    delay(10000);
    ForwardTheLightBrigade();
  }
  else
  {
    ForwardTheLightBrigade();
  }
}

void ForwardTheLightBrigade()
{
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);    
}

void HaltAndCatchFire()
{
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}
