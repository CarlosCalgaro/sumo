#include <Arduino.h>

enum Direction {
  Forward = 1,
  Backward = 2,
  Right = 3,
  Left = 4
};

#define LEFT_MOTOR 6
#define RIGHT_MOTOR 11
#define LEFT_MOTOR_DIRECTION  8
#define RIGHT_MOTOR_DIRECTION  13

void disableMotors();
void enableMotors();
void turnMotors(Direction direction);
void turnBackwards();
void turnForwards();
void turnRight();
void turnLeft();