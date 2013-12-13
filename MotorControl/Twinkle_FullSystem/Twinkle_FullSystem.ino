#include <Servo.h>
#include <QuadEncoder.h>

const int BAUD_RATE = 9600;
boolean Twinkle = true;

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
    delay(10000);
    
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
    MoveString(1, 7);
    QuarterWait(2);
    
    //E
    Serial.println("Star");
    MoveString(1, -7);
    QuarterWait(1);
    LiftUpString(1);
    
    //D, D
    //MoveString(2, 65);
    MoveString(2, 5);
    Serial.println("How I");
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("Wonder");
    MoveString(2, -15);
    QuarterWait(2);
    
    //B, B
    Serial.println("What You");
    MoveString(2, -30);
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
    
    //D, D
    Serial.println("-Bove the");
    MoveString(2, 65);
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("World So");
    MoveString(2, -15);
    QuarterWait(2);
    
    //B
    Serial.println("High");
    MoveString(2, -30);
    QuarterWait(1);
    LiftUpString(2);
    QuarterWait(1);
    
    //E, E
    Serial.println("Like A");
    PushDownString(1);
    QuarterWait(1);
    
    //D, D
    MoveString(2, 45);
    Serial.println("Diamond");
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("In The");
    MoveString(2, -15);
    QuarterWait(2);
    
    //B
    Serial.println("Sky");
    MoveString(2, -30);
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
    MoveString(1, 7);
    QuarterWait(2);
    
    //E
    Serial.println("Star");
    MoveString(1, -7);
    QuarterWait(1);
    LiftUpString(1);
    QuarterWait(1);
    
    //D, D
    MoveString(2, 65);
    Serial.println("How I");
    PushDownString(2);
    QuarterWait(2);
    
    //C, C
    Serial.println("Wonder");
    MoveString(2, -15);
    QuarterWait(2);
    
    //B, B
    Serial.println("What you");
    MoveString(2, -30);
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
  
}

void QuarterWait(int num)
{
  delay(1000 * num);
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
    servo1.write(35);
  }
  if (string == 2)
  {
    servo2.write(40);
  }
  if (string == 3)
  {
    servo3.write(50);
  }
  if (string == 4)
  {
    servo4.write(50);
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
  
  
  long failTime = 10000; // 10 seconds
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
    
    if (moved == '-'){
     //do nothing
    }else{
     ticks = moved;
    }
  }
  
  HoldString(pin1, pin2);
  Serial.print("Finished moving string ");
  Serial.print(ticksToMove);
  Serial.println(" ticks");
}
  
