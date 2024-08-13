#include "HX711.h"
#include <Keyboard.h>

float calibrationFactor = 259.03;
HX711 hxScale;

void setup()
{
  pinMode(4, INPUT_PULLUP);
  hxScale.begin(2, 3);
  Keyboard.begin();
  hxScale.set_scale(calibrationFactor);
  delay(100);
  hxScale.tare();
}

void loop(){
  while (digitalRead(4) == HIGH) {}
  
  float calibrationFactor = hxScale.get_units(10);
  Keyboard.println(String(calibrationFactor));
}
