#include "Arduino.h"
#include "motor.h"

void disableMotors(){
  digitalWrite(LEFT_MOTOR, LOW);
  digitalWrite(RIGHT_MOTOR, LOW);
}

void enableMotors(){
  digitalWrite(LEFT_MOTOR, HIGH);
  digitalWrite(RIGHT_MOTOR, HIGH);
}

void turnMotors(Direction direction){
  if(direction == Direction::Forward){
    turnForwards();
  }
  else if(direction == Direction::Backward){
    turnBackwards();
  }
  else if(direction == Direction::Right){
    turnRight();
  }
  else if(direction == Direction::Left){
    turnLeft();
  }
}

void turnBackwards(){
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
}

void turnForwards(){
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
}

void turnRight(){
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
}
void setMotorPower(int power){
  analogWrite(LEFT_MOTOR, power);
  analogWrite(RIGHT_MOTOR, power);
}
void turnLeft(){
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
}