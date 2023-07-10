#ifndef __Setup_H
#define __Setup_H
#include <Arduino.h>

enum State{
  IDLE = 0,
  SEARCHING = 1, 
  CHARGING = 2,
  RECOVERING = 3,
};

extern State currentState;

void handleTargetFound();
void handleOutOfArena();
void handleInArena();
void setup();

#endif