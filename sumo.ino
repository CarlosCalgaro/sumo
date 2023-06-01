#include "setup.h"
#include <infrared_sensor.h>
#include <motor.h>
#include <ultrasonic_sensor.h>

bool FOUND = false;
void loop() {
  switch(currentState){
    case State::IDLE:
      Serial.println("Idle");
      break;
    case State::SEARCHING:
      Serial.println("Searching");
      break;
    case State::CHARGING:
      Serial.println("Charging");
      break;
    case State::RECOVERING:
      Serial.println("RECOVERING");
      break;
    default:
      break;
  }
}