
#ifndef __Motor_h
#define __Motor_h

#include <Arduino.h>
#define LEFT_MOTOR 6
#define RIGHT_MOTOR 11
#define LEFT_MOTOR_DIRECTION  8
#define RIGHT_MOTOR_DIRECTION  13

enum Direction {
  Forward = 1,
  Backward = 2,
  Right = 3,
  Left = 4
};

void disableMotors();
void enableMotors();
void turnMotors(Direction direction);
void turnBackwards();
void turnForwards();
void turnRight();
void turnLeft();
void setMotorPower(int power);
#endif