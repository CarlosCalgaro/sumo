#include "setup.h"
#include "infrared_sensor.h"
#include "motor.h"
#include "ultrasonic_sensor.h"
#define SEARCH_DISTANCE 40

bool FOUND = false;
void handleSearch();

void loop() {
  switch(currentState){
    case State::IDLE:
      Serial.println("Idle");
      break;
    case State::SEARCHING:
      Serial.println("Searching");
      handleSearch();
      break;
    case State::CHARGING:
      Serial.println("Charging");
      handleCharging();
      break;
    case State::RECOVERING:
      Serial.println("RECOVERING");
      delay(500);
      currentState = State::SEARCHING;
      break;
    default:
      break;
  }
}

void handleCharging(){
  setMotorPower(255);
  if(getDistance() < SEARCH_DISTANCE){
    turnForwards();
  }else{
    currentState = State::SEARCHING;
  }
};

void handleSearch(){
  setMotorPower(125);
  turnLeft();
  if(getDistance() < SEARCH_DISTANCE){
    currentState = State::CHARGING;
  }else{
    currentState = State::SEARCHING;
  }
};
