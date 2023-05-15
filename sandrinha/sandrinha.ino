#include "setup.h"
#include "motor.h"
#include "ultrasonic_sensor.h"
#include "infrared_sensor.h"

bool FOUND = false;
void loop() {

  Brightness brightness = getBrightness();
  Serial.println(brightness);
  if(brightness == Brightness::Light){
    turnBackwards();
    delay(300);
    turnLeft();
    delay(500);
    turnRight();
    delay(100);
  }else{
    turnForwards();
  }
}