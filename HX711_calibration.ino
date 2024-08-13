#include "HX711.h"
#include <Keyboard.h>

float knownWeight = 300.0;
HX711 hxScale;

void setup()
{
  pinMode(4, INPUT_PULLUP);
  hxScale.begin(2, 3);
  Keyboard.begin();
  delay(100);
  hxScale.tare();
  Keyboard.println("Place the known weight on the scale then press Tare button");
}

void loop(){
  while (digitalRead(4) == HIGH) {}
  
  float calibrationFactor = hxScale.get_units(10) / knownWeight;
  Keyboard.print("Calibration factor: ");
  Keyboard.println(String(calibrationFactor));
}
