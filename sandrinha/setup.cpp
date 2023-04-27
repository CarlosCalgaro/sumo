#include "setup.h"
#include "motor.h"
#include "ultrasonic_sensor.h"

void setup() {
  Serial.begin(9600);
  //motor.h
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  pinMode(LEFT_MOTOR_DIRECTION, OUTPUT);
  pinMode(RIGHT_MOTOR_DIRECTION, OUTPUT);
  //ultrasonic_sensor.h
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}