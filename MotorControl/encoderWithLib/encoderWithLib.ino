#include <QuadEncoder.h>

int moved=0;
QuadEncoder encoder(2,3);

void setup() {
    Serial.begin(9600);
}

void loop() {
  moved=encoder.tick();
  if (moved=='>')
    Serial.print(char(moved));
  else if (moved=='<')
    Serial.print(char(moved));
}
