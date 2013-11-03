#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
QuadEncoder encoder(1, 2);

const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;

int B = 0;
int A = -13;
int G = -26;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT); 
}

int ticks = 0;
boolean firstTime = true;

void loop()
{
  if (firstTime)
  {
    Serial.println("Ready");
    //Hot Cross Buns Song
    //Go to beginning of song - B not
    delay(1000);
    Serial.println("Starting song");
    //B
    //A
    MoveString(B, A);
    Serial.println("A");
    delay(1000);
    //G
    MoveString(A, G);
    Serial.println("G");
    delay(2000);
    //B
    MoveString(G, B);
    Serial.println("B");
    delay(1000);
    //A
    MoveString(B, A);
    Serial.println("A");
    delay(1000);
    //G
    MoveString(A, G);
    Serial.println("G");
    delay(3000);
    //G, G, G, G
    //A, A, A, A
    MoveString(G, A);
    Serial.println("A");
    delay(1000);
    //B
    MoveString(A, B);
    Serial.println("B");
    delay(1000);
    //A
    MoveString(B, A);
    Serial.println("A");
    delay(1000);
    //G
    MoveString(A, G);
    Serial.println("G");
    delay(4000);
    firstTime = false;
  }
}

void MoveString(int current, int next)
{
  int ticksToMove = next - current;
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
