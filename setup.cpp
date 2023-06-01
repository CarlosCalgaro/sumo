#include "infrared_sensor.h"
#include "motor.h"
#include "ultrasonic_sensor.h"
#include "setup.h"

State currentState = State::SEARCHING;
void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(INFRARED_PIN), handleOutOfArena, FALLING);
  // led
  pinMode(13, OUTPUT);
  //motor.h
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  pinMode(LEFT_MOTOR_DIRECTION, OUTPUT);
  pinMode(RIGHT_MOTOR_DIRECTION, OUTPUT);
  //ultrasonic_sensor.h
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  //infrared_sensor.h
  pinMode(INFRARED_PIN, INPUT);
  turnMotors(Direction::Forward);
}

void handleOutOfArena(){
  currentState = State::RECOVERING;
};