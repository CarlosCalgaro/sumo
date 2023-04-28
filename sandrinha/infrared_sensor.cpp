#include "infrared_sensor.h"

Brightness getBrightness(){
  Brightness brightness = digitalRead(INFRARED_PIN);

  if (brightness == Brightness::Dark)
    Serial.println("Brightness: Dark");
  else
    Serial.println("Brightness: Light");

  return brightness;
}