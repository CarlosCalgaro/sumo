#include "infrared_sensor.h"

Brightness getBrightness(){
  Brightness brightness = digitalRead(INFRARED_PIN);
  return brightness;
}