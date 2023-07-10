#include "setup.h"
#include "infrared_sensor.h"
#include "motor.h"
#include "ultrasonic_sensor.h"
#define SEARCH_DISTANCE 36

bool FOUND = false;
void handleSearch();

void loop() {
  // currentState = State::IDLE;
  switch(currentState){
    case State::IDLE:
      Serial.println("Sensor de ultrassom:");
      Serial.println(getDistance());
      Serial.println("Sensor de cor:");
      Serial.println(getBrightness());
      Serial.println("\n");
      break;
    case State::SEARCHING:
      handleSearch();
      break;
    case State::CHARGING:
      handleCharging();
      break;
    case State::RECOVERING:
      setMotorPower(197);
      enableMotors();
      turnBackwards();
      delay(750);
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
  float distance = getDistance();
  Serial.println(distance);
  if(getDistance() < SEARCH_DISTANCE){
  
    currentState = State::CHARGING;
  }
};
