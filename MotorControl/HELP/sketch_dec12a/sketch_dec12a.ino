#include <QuadEncoder.h>

const int BAUD_RATE = 9600;

const int Motor3Pin1 = 22;
const int Motor3Pin2 = 24;


void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(Motor3Pin1, OUTPUT);   
  pinMode(Motor3Pin2, OUTPUT); 
}

void loop()
{
  //to stop, hold at high
  digitalWrite(Motor3Pin1, LOW);
  digitalWrite(Motor3Pin2, LOW); 
  
}
