/*
Tuning script used to tighten and loosen a string based on the "ticks" from the encoder
Values larger than 3 digits are truncated to 3 digits
Negetive values are supported
*/
#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
QuadEncoder encoder(1, 2);
char message[4];
int ticksToMove;
int index;
int ticks;
const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT); 
}

void MoveString(char message[])
{
  ticksToMove = atoi(message);
  Serial.print("Read: ");
  Serial.println(message);
  ticks = 0;
  
  if (ticksToMove > 0)
  {
    Serial.println("positive");
    TightenString(ticksToMove);
  }
  else
  {
    Serial.println("negative");
    LoosenString(ticksToMove);
  }
   
  int moved = encoder.tick();
  if (moved == '>' || moved == '<')
  {
    ticks += 1;
    Serial.println(ticks);
  }
  
  if (ticks >= ticksToMove)
  {
    
    digitalWrite(Motor1Pin1, LOW);
    digitalWrite(Motor1Pin2, LOW); 
  }
}

void TightenString(int ticksToMove){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
}

void LoosenString(int ticksToMove){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
}
  
void loop()
{
  if (Serial.available())
  {
    for (int i = 0; i < 4; i++)
    {
      message[i] = '\0';  
    }
    delay(100);
    while(Serial.available())
    {
      if (index < 3)
      {
        message[index] = Serial.read();
        index++;
      }
      else
      {
        Serial.read(); 
      }
    }  
   
    
    MoveString(message);
    index = 0;
  }
}
