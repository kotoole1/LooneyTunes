/*
Tuning script used to tighten and loosen a string based on the "ticks" from the encoder
Values larger than 3 digits are truncated to 3 digits
Negetive values are supported
*/
#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
QuadEncoder encoder(1, 2);
const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT); 
}

void MoveString(int ticksToMove)
{
  long failTime = 10000; // 10 seconds
  long failTimer = millis();
  int ticks = 0;
  while (ticks < abs(ticksToMove))
  {
    if (millis() - failTimer > failTime)
    {
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

void TightenString(int pin1, int pin2)
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void LoosenString(int pin1, int pin2)
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
