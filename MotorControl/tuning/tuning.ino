/*
Tuning script used to tighten and loosen a string based on the "ticks" from the encoder
Values larger than 3 digits are truncated to 3 digits
Negetive values are supported
*/
#include <QuadEncoder.h>
#include <Servo.h>

const int BAUD_RATE = 9600;

//Servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int servo1pin = 2;
const int servo2pin = 3;
const int servo3pin = 4;
const int servo4pin = 5;

const int bow_motorpin1 = 22;
const int bow_motorpin2 = 24;

//String 1
//QuadEncoder encoder(53, 51);
//const int Motor1Pin1 = 52;
//const int Motor1Pin2 = 50;

////String 2
////Small encoder
QuadEncoder encoder(49, 47);
const int Motor1Pin1 = 48;
const int Motor1Pin2 = 46;

//String 3
//QuadEncoder encoder(45, 43);
//const int Motor1Pin1 = 44;
//const int Motor1Pin2 = 42;

//String 4
//QuadEncoder encoder(41, 39);
//const int Motor1Pin1 = 40;
//const int Motor1Pin2 = 38;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT); 
  
  //Attach servos
  servo1.attach(servo1pin); 
  servo2.attach(servo2pin); 
  servo3.attach(servo3pin); 
  servo4.attach(servo4pin); 
  
  pinMode(bow_motorpin1, OUTPUT);   
  pinMode(bow_motorpin2, OUTPUT);
}

void MoveString(int ticksToMove)
{
  long failTime = 10000; // 1 seconds
  long failTimer = millis();
  int ticks = 0;
  while (ticks < abs(ticksToMove))
  {
    if (millis() - failTimer > failTime)
    {
      Serial.println("");
      Serial.println("Stalled trying to move the motor");
      HoldString(Motor1Pin1, Motor1Pin2);
      return;
    }
    
    if (ticksToMove > 0)
    {
      TightenString(Motor1Pin1, Motor1Pin2);  
    }
    else
    {
      LoosenString(Motor1Pin1, Motor1Pin2);   
    }
    
    int moved = encoder.tick();
    //CHECK THAT THE ENCODER IS WORKING BY PRINTING THE TICK!!
    Serial.print(moved);
    if (moved == '>' || moved == '<')
    {
      ticks += 1;
    }
  }
  
  HoldString(Motor1Pin1, Motor1Pin2);
  Serial.print("Finished moving string ");
  Serial.print(ticksToMove);
  Serial.println(" ticks");
}

void LoosenString(int pin1, int pin2)
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void TightenString(int pin1, int pin2)
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

void HoldString(int pin1, int pin2)
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW); 
}
  
void loop()
{
  
  //STOP BOW
  digitalWrite(bow_motorpin1, LOW);
  digitalWrite(bow_motorpin2, LOW); 
  
  //Push strings down
  servo1.write(55);
  servo2.write(65);
  servo3.write(85);
  servo4.write(85);
  
  if (Serial.available())
  {
    int index = 0;
    char message[4];
    
    // Erase what was previously in the buffer
    for (int i = 0; i < 4; i++)
    {
      message[i] = '\0';  
    }
    
    // Wait for the entire message to fill the buffer
    delay(100);
    
    // Read from the buffer
    while(Serial.available())
    {
      // Read the first 3 values in the buffer
      if (index < 3)
      {
        message[index] = Serial.read();
        index++;
      }
      // And truncate the rest of the values
      else
      {
        Serial.flush(); 
      }
    }
    // Move the string according to how many ticks message specifies
    Serial.println(atoi(message));
    MoveString(atoi(message));
  }
}
