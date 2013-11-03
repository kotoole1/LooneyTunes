#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
QuadEncoder encoder(1, 2);

const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;

int B = 0;
int A = -15;
int G = -27;

void setup()
{
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT); 
  Serial.begin(BAUD_RATE);
  delay(1000);
}

int ticks = 0;
boolean firstTime = true;

void loop()
{
  /*
  if (firstTime)
  {
    Serial.println("Ready");
    //Hot Cross Buns Song
    //Go to beginning of song - B note
    MoveStringOne(G, B);
    /*
    delay(1000);
    //B
    //A
    MoveStringOne(B, A);
    delay(1000);
    //G
    MoveStringOne(A, G);
    delay(2000);
    //B
    MoveStringOne(G, B);
    delay(1000);
    //A
    MoveStringOne(B, A);
    delay(1000);
    //G
    MoveStringOne(A, G);
    delay(3000);
    //G, G, G, G
    //A, A, A, A
    MoveStringOne(G, A);
    delay(1000);
    //B
    MoveStringOne(A, B);
    delay(1000);
    //A
    MoveStringOne(B, A);
    delay(1000);
    //G
    MoveStringOne(A, G);
    delay(4000);
    firstTime = false;
  }*/
  
  int moved = encoder.tick();
  if (moved == '>' || moved == '<')
  {
    ticks += 1;
    Serial.println(ticks);
    digitalWrite(Motor1Pin1, LOW);
    digitalWrite(Motor1Pin2, LOW); 
    delay(1000);
  }
  else
  {
    digitalWrite(Motor1Pin1, HIGH);
    digitalWrite(Motor1Pin2, LOW); 
  }
  
}

void MoveStringOne(int current, int next)
{
  int ticks = 0;
  int moved = 0;
  int totalTicks = next - current;
  boolean isUp = (totalTicks > 0); 
  
  
  while (ticks < totalTicks)
  {
    MoveString(isUp);
    moved = encoder.tick();
    if (moved == '>' || moved == '<')
    {
      ticks += 1;
    }
  }
  HoldString();
}

void MoveString(int isUp){
  
  if(isUp){
    TightenString();
  } else {
    LoosenString();
  }
  
}

void HoldString(){
  
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);

}

void TightenString() {
  
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  
}

void LoosenString() {
  
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  
}
