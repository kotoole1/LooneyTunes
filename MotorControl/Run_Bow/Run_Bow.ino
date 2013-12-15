

#include <Servo.h>
const int BAUD_RATE = 9600;

const int BowMotor1 = 22;
const int BowMotor2 = 24;

//Servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int servo1pin = 2;
const int servo2pin = 3;
const int servo3pin = 4;
const int servo4pin = 5;



void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(BowMotor1, OUTPUT);   
  pinMode(BowMotor2, OUTPUT);
 
 //Attach servos
  servo1.attach(servo1pin); 
  servo2.attach(servo2pin); 
  servo3.attach(servo3pin); 
  servo4.attach(servo4pin);  
}

void loop()
{
  
  //Push strings down
  servo1.write(0);  //50 is down, -10 is up
  servo2.write(0);  //60 is down
  servo3.write(0);  //85 is down
  servo4.write(85);  //85 is down
  
  digitalWrite(BowMotor1, LOW);
  digitalWrite(BowMotor2, HIGH); 
  
}
