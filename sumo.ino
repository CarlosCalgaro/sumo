#include "setup.h"
#include "infrared_sensor.h"
#include "motor.h"
#include "ultrasonic_sensor.h"

bool FOUND = false;
void loop() {
  // delay(300);
  switch(currentState){
    case State::IDLE:
      Serial.println("Idle");
      break;
    case State::SEARCHING:
      Serial.println("Searching");
      if(getDistance() < 20){
        currentState = State::CHARGING;
      }else{
        currentState = State::SEARCHING;
      }
      break;
    case State::CHARGING:
      Serial.println("Charging");
      break;
    case State::RECOVERING:
      Serial.println("RECOVERING");
      delay(3000);
      currentState = State::SEARCHING;
      break;
    default:
      break;
  }
}