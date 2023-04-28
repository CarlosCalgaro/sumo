#include <Arduino.h>

#define INFRARED_PIN 3

enum Brightness {
  Dark = 1,
  Light = 2
};

Brightness getBrightness();