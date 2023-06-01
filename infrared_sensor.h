
#ifndef __Infrared_Sensor_h
#define __Infrared_Sensor_h
#include <Arduino.h>

#define INFRARED_PIN 3

enum Brightness {
  Dark = 1,
  Light = 0
};

Brightness getBrightness();
#endif