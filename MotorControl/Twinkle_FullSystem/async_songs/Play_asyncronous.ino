#include <Servo.h>
#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
boolean Twinkle = true;
boolean Imperial = false;
boolean HappyBirthday = false;

//Encoders
QuadEncoder encoder1_detailed(53, 51);    //works negative tightens
QuadEncoder encoder2_detailed(49, 47);    //works negative tightens
QuadEncoder encoder3_detailed(45, 43);    //works negative tightens
QuadEncoder encoder4_detailed(41, 39);    //works negative loosens the string

QuadEncoder encoder1(37, 35);    //works
QuadEncoder encoder2(33, 31);    //works!!!! (make sure the timeout is long enough)
QuadEncoder encoder3(29, 27);    //works!!!!
QuadEncoder encoder4(25, 23);    //works tightens loosens the string

//Motors
const int motor1pin1 = 52;
const int motor1pin2 = 50;
const int motor2pin1 = 48;
const int motor2pin2 = 46;
const int motor3pin1 = 44;
const int motor3pin2 = 42;
const int motor4pin1 = 40;
const int motor4pin2 = 38;

const int bow_motorpin1 = 22;
const int bow_motorpin2 = 24;

//Servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int servo1pin = 2;
const int servo2pin = 3;
const int servo3pin = 4;
const int servo4pin = 5;

int pos = 0;
boolean firstTime = false;


void setup() 
{ 
  Serial.begin(BAUD_RATE);
  
  //Attach servos
  servo1.attach(servo1pin); 
  servo2.attach(servo2pin); 
  servo3.attach(servo3pin); 
  servo4.attach(servo4pin); 
  
  //Configure digital pins to output
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);   
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);   
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);   
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  pinMode(bow_motorpin1, OUTPUT);   
  pinMode(bow_motorpin2, OUTPUT);
  
  
  
} 

void loop() 
{ 
  
  if (Twinkle)
  {
    StartSong();
    
    // A, A
    Serial.println("Twinkle");
    PushDownString(2);
    QuarterWait(2);
    LiftUpString(2);
    
    //E, E
    Serial.println("Twinkle");
    PushDownString(1);
    QuarterWait(2);
    
    //F, F
    Serial.println("Little");
    MoveString(1, 4);
    QuarterWait(2);
    
    //E
    Serial.println("Star");
    MoveString(1, -4);
    QuarterWait(2);
    LiftUpString(1);
    
    //D, D
    MoveString(2, 55);
    Serial.println("How I");
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("Wonder");
    MoveString(2, -10);
    QuarterWait(2);
    
    //B, B
    Serial.println("What You");
    MoveString(2, -20);
    QuarterWait(2);
    
    //A
    Serial.println("Are");
    MoveString(2, -20);
    QuarterWait(1);
    LiftUpString(2);
    
    //E, E
    Serial.println("Up a-");
    PushDownString(1);
    QuarterWait(2);
    LiftUpString(1);
    
    //D, D
    Serial.println("-Bove the");
    MoveString(2, 55);
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("World So");
    MoveString(2, -10);
    QuarterWait(2);
    
    //B
    Serial.println("High");
    MoveString(2, -20);
    QuarterWait(1);
    LiftUpString(2);
    QuarterWait(1);
    
    //E, E
    Serial.println("Like A");
    PushDownString(1);
    QuarterWait(2);
    LiftUpString(1);
    
    //D, D
    MoveString(2, 30);
    Serial.println("Diamond");
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("In The");
    MoveString(2, -10);
    QuarterWait(2);
    
    //B
    Serial.println("Sky");
    MoveString(2, -20);
    QuarterWait(1);
    
     //A, A
     Serial.println("Twinkle");
    MoveString(2, -20);
    QuarterWait(2);
    LiftUpString(2);
    
     //E, E
     Serial.println("Twinkle");
    PushDownString(1);
    QuarterWait(2);
    
    //F, F
    Serial.println("Little");
    MoveString(1, 4);
    QuarterWait(2);
    
    //E
    Serial.println("Star");
    MoveString(1, -4);
    QuarterWait(2);
    LiftUpString(1);
    
    //D, D
    MoveString(2, 55);
    Serial.println("How I");
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("Wonder");
    MoveString(2, -10);
    QuarterWait(2);
    
    //B, B
    Serial.println("What you");
    MoveString(2, -20);
    QuarterWait(2);
    
    //A
    Serial.println("Are");
    MoveString(2, -20);
    QuarterWait(1);
    LiftUpString(2);
    QuarterWait(1);
    
    EndSong();
  }
  Twinkle = false;
  
  if (Imperial){
    
    StartSong();
    
    //Move D string to F
    MoveString(3, 31);   
    
    //Play three A's
    PushDownString(2);
    QuarterWaitImperial(1);
    QuarterWaitImperial(1);
    QuarterWaitImperial(1);
    LiftUpString(2);
   
    MoveString(2, 31);
    
    PushDownString(3);
    QuarterWaitImperial(0.75);
    LiftUpString(3);
    
    PushDownString(2);
    QuarterWaitImperial(0.25);
    
    MoveString(2, -31);
    QuarterWaitImperial(1);
    
    LiftUpString(2);
    MoveString(2, 31);
    
    
    PushDownString(3);
    QuarterWaitImperial(0.75);
    
    LiftUpString(3);
    PushDownString(2);
    QuarterWaitImperial(0.25);
    
    MoveString(2, -31);
    QuarterWaitImperial(2);
    
    // Start on the higher part
    LiftUpString(2);
    MoveString(1, 17);
    PushDownString(1);
    QuarterWaitImperial(1);
    
    LiftUpString(1);
    PushDownString(2);
    QuarterWaitImperial(0.75);
    QuarterWaitImperial(0.25);
    
    LiftUpString(2);
    PushDownString(1);
    QuarterWaitImperial(1);
    LiftUpString(1);
    
    MoveString(1, -2);
    PushDownString(1);
    QuarterWaitImperial(0.75);
    
    MoveString(1, -2);
    QuarterWaitImperial(0.25);
    
    MoveString(1, -2);
    QuarterWaitImperial(0.25);
 
    MoveString(1, -1);
    QuarterWaitImperial(0.25);
    
    MoveString(1, 1);
    QuarterWaitImperial(0.5);
    
    LiftUpString(1);
    // Rest
    QuarterWaitImperial(0.5);
    
    MoveString(2, 7);
    PushDownString(2);
    QuarterWaitImperial(0.5);
    LiftUpString(2);
    //o
    
    MoveString(1, -8);
    LiftUpString(2);
    PushDownString(1);
    QuarterWaitImperial(1);
    
    MoveString(2, 50);
    LiftUpString(1);
    PushDownString(2);
    QuarterWaitImperial(0.75);
    
    MoveString(2, -5);
    QuarterWaitImperial(0.25);

    MoveString(2, -8);
    QuarterWaitImperial(0.25);

    MoveString(2, -10);
    QuarterWaitImperial(0.25);

    MoveString(2, 10);
    QuarterWaitImperial(0.5);
    
    // Rest
    LiftUpString(2);
    QuarterWaitImperial(0.5);
    
    PushDownString(3);
    QuarterWaitImperial(0.5);
    //added
    LiftUpString(3);
    
    MoveString(3, 51);
    //added
    PushDownString(3);
    QuarterWaitImperial(1);
    
    MoveString(3, -51);
    //added
    PushDownString(3);
    QuarterWaitImperial(0.75);
    
    LiftUpString(3);
    PushDownString(2);
    QuarterWaitImperial(0.25);
    
    MoveString(2, -31);
    QuarterWaitImperial(1);

    LiftUpString(2);
    PushDownString(3);
    MoveString(2, 31);
    QuarterWaitImperial(0.75);
    
    LiftUpString(3);
    PushDownString(2);
    QuarterWaitImperial(0.25);
    
    MoveString(2, -31);
    QuarterWaitImperial(1);
    
    EndSong();
    
    //Set strings to E, A, and D
    MoveString(3, -30);
    MoveString(1, 4);
    MoveString(2, -7);
    
    
  }
  
  Imperial = false;
  
  if (HappyBirthday){
    
   StartSong();
   
   //Make D string A
   MoveString(3, 90);
   MoveString(3, 40);
   
   //A, A
   PushDownString(2);
   QuarterWait(2);
   LiftUpString(2);
   
   //B
   MoveString(2, 18);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //A
   MoveString(2, -20);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //D
   MoveString(2, 55);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //C
   MoveString(2, -10);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
    //A, A
   MoveString(2, -40);
   PushDownString(2);
   QuarterWait(2);
   LiftUpString(2);
   
   //B
   MoveString(2, 18);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //A
   MoveString(2, -20);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //E
   PushDownString(1);
   QuarterWait(1);
   LiftUpString(1);
   
   //D
   MoveString(2, 55);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   
   //Play open A on D string
   //A, A
   PushDownString(3);
   QuarterWait(2);
   LiftUpString(3);
   
   //A (E string)
   MoveString(1, 19);
   PushDownString(1);
   QuarterWait(1);
   LiftUpString(1);
   
   //F
   MoveString(1, -11);
   PushDownString(1);
   QuarterWait(1);
   LiftUpString(1);
   
   //D
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
    //C
   MoveString(2, -10);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //B
   MoveString(2, -10);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //G
   MoveString(1, 4);
   PushDownString(1);
   QuarterWait(2);
   LiftUpString(1);
   
   //F
   MoveString(1, -4);
   PushDownString(1);
   QuarterWait(1);
   LiftUpString(1);
   
   //D
   MoveString(2, 35);
   PushDownString(2);
   QuarterWait(1);
   LiftUpString(2);
   
   //E
   MoveString(1, -4);
   PushDownString(1);
   QuarterWait(1);
   LiftUpString(1);
   
   //D
   PushDownString(2);
   QuarterWait(1);
   
  
   EndSong();
   
   //Move D string back to D
   MoveString(3, -90);
   MoveString(3, -34);
   MoveString(2, -50);
   
    
  }
  HappyBirthday = false;
  
}

void QuarterWait(int num)
{
  delay(1000 * num);
}

void QuarterWaitImperial(float num)
{
  delay(800 * num);    
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

void PushDownString(int string)
{
  
  if (string == 1)
  {
    servo1.write(55);
  }
  if (string == 2)
  {
    servo2.write(65);
  }
  if (string == 3)
  {
    servo3.write(85);
  }
  if (string == 4)
  {
    servo4.write(85);
  }
}

void LiftUpString(int string)
{
  
  if (string == 1)
  {
    servo1.write(0);
  }
  if (string == 2)
  {
    servo2.write(0);
  }
  if (string == 3)
  {
    servo3.write(0);
  }
  if (string == 4)
  {
    servo4.write(0);
  }
}

void StartSong()
{
 
 //Lift up all strings
 LiftUpString(1);
 LiftUpString(2);
 LiftUpString(3);
 LiftUpString(4);
 
 //Start bow axle
 digitalWrite(bow_motorpin1, HIGH);
 digitalWrite(bow_motorpin2, LOW); 
 
 delay(10000);
}
 
void EndSong()
{
  //Detach servos
  servo1.detach();
  servo2.detach();
  servo3.detach();
  servo4.detach();
  
  digitalWrite(bow_motorpin1, LOW);
  digitalWrite(bow_motorpin2, LOW); 
}
  

void UpdateStrings()
{
  for (int string=1; string<=4; string++) {
    

  }
}
  
void MoveString(int string, int ticksToMove)
{
  
  int pin1;
  int pin2;
  int encoderpin1;
  int encoderpin2;
  
  
  if (string == 1)
  {
    pin1 = motor1pin1;
    pin2 = motor1pin2;
    encoderpin1 = 53;
    encoderpin2 = 51;
    
  }
  if (string == 2)
  {
    pin1 = motor2pin1;
    pin2 = motor2pin2;
    encoderpin1 = 49;
    encoderpin2 = 47;
  }
  if (string == 3)
  {
    pin1 = motor3pin1;
    pin2 = motor3pin2;
    encoderpin1 = 45;
    encoderpin2 = 43;
  }
  if (string == 4)
  {
    pin1 = motor4pin1;
    pin2 = motor4pin2;
    encoderpin1 = 41;
    encoderpin2 = 39;
  }
  
  QuadEncoder encoder(encoderpin1, encoderpin2);
  
  
  long failTime = 10000; // 1 seconds
  long failTimer = millis();
  int ticks = 0;
  while (ticks < abs(ticksToMove))
  {
    if (millis() - failTimer > failTime)
    {
      Serial.println("");
      Serial.println("Stalled trying to move the motor");
      HoldString(pin1, pin2);
      return;
    }
    
    if (ticksToMove > 0)
    {
      TightenString(pin1, pin2);  
    }
    else
    {
      LoosenString(pin1, pin2);   
    }
    
    int moved = encoder.tick();
    //CHECK THAT THE ENCODER IS WORKING BY PRINTING THE TICK!!
    Serial.print(moved);
    if (moved == '>' || moved == '<')
    {
      ticks += 1;
    }
  }
  
  HoldString(pin1, pin2);
  Serial.print("Finished moving string ");
  Serial.print(ticksToMove);
  Serial.println(" ticks");
}

  
