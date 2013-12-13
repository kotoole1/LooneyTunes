
const int BAUD_RATE = 9600;

const int BowMotor1 = 36;
const int BowMotor2 = 34;


void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(BowMotor1, OUTPUT);   
  pinMode(BowMotor2, OUTPUT); 
}

void loop()
{
  digitalWrite(BowMotor1, HIGH);
  digitalWrite(BowMotor2, LOW); 
  
}
