#include <QuadEncoder.h>
#include <Servo.h>

#define SCHEDULE_LENGTH 1
#define NUM_STRINGS 4
#define SERVO_DOWN_STATE 55
#define MOTOR_TIGHTENING 1
#define MOTOR_STOPPED 0
#define MOTOR_LOOSENING -1

const int BAUD_RATE = 9600;
long int timer;

byte motorPins[NUM_STRINGS][2] = {{}, {}, {}, {}};
byte stringsMoving[NUM_STRINGS] = {MOTOR_STOPPED, MOTOR_STOPPED, MOTOR_STOPPED, MOTOR_STOPPED};

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

byte servoPins[4] = {1, 2, 3, 4};

Servo *servos[4] = {&servo1, &servo2, &servo3, &servo4};

byte encoderPins[NUM_STRINGS][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}};
int encoderPositions[NUM_STRINGS][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
QuadEncoder *encoders[NUM_STRINGS][2];

long int stringSchedules[NUM_STRINGS][SCHEDULE_LENGTH][4];

// Keep track of where each string is in their respective schedules
byte stringIndices[NUM_STRINGS] = {0, 0, 0, 0};

// Things that should happen only at the beginning of the song should go in the guard clause in loop()
// that's protected by this bool
boolean firstTime = true;

void setup()
{
  Serial.begin(BAUD_RATE);
  
  for (int i = 0; i < NUM_STRINGS; i++)
  {
    (*servos[i]).attach(servoPins[i]);
    
    int motorPin1 = motorPins[i][0];
    int motorPin2 = motorPins[i][1];
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
  }
  
  for (int i = 0; i < NUM_STRINGS; i++)
  {
    *encoders[i][1] = QuadEncoder(encoderPins[i][1][1], encoderPins[i][1][2]);
    *encoders[i][2] = QuadEncoder(encoderPins[i][2][1], encoderPins[i][2][2]);  
  }
  
  HotCrossBuns(); 
}

void loop()
{
  if (firstTime)
  {
    firstTime = false; 
    timer = millis();
  }
  
  for (int i = 0; i < NUM_STRINGS; i++)
  {
    UpdateStringState(stringIndices[i]); 
    UpdateEncoders(stringIndices[i]);
//    UpdateStringTension(stringIndices[i]);
  }
}


void UpdateStringState(byte currentString)
{
  long int nextStringNote = stringSchedules[currentString][stringIndices[currentString]][0];
  long int nextStringPos = stringSchedules[currentString][stringIndices[currentString]][1];
  long int nextStringOn = stringSchedules[currentString][stringIndices[currentString]][2];
  long int nextStringOff = stringSchedules[currentString][stringIndices[currentString]][3];
  
  
  if (TimeFor(nextStringOn)) 
  { 
    SetServoPosition(currentString, true);
    stringIndices[currentString] += 1;
  }
  if (TimeFor(nextStringOff)) { SetServoPosition(currentString, false); }
  if (TimeFor(nextStringNote)) 
  {
    // Write a new position
  }
}

void UpdateEncoders(byte index)
{
   int ticked1 = (*encoders[index][1]).tick();
   int ticked2 = (*encoders[index][2]).tick();
   
   if (ticked1 == '>') { (encoderPositions[index][1])++; }
   else if (ticked1 == '<') { (encoderPositions[index][1])--; }
   
   if (ticked2 == '>') { (encoderPositions[index][2])++; }
   else if (ticked2 == '<') { (encoderPositions[index][2])--; } 
}

void UpdateStringTension(byte index)
{
      
}


/* Is it time for a specific event to occur?
 * @param time: The time that an event is scheduled to occur, in ms 
 */
boolean TimeFor(long int time)
{
  return (millis() - timer >= time);  
}

void SetServoPosition(byte servoIndex, boolean on)
{
  if (on) { (*servos[servoIndex]).write(SERVO_DOWN_STATE); }
  else { (*servos[servoIndex]).write(0); }
}


//void TwinkleTwinkle()
//{
//}

void HotCrossBuns()
{
}
