// Drive Stop Turn

#include <RedBot.h>

RedBotMotors motors;

#define s_drive 0
#define s_stop 1
#define s_turn 2
int robot_state = 0;

void loop() {
  transition(robot_state);
  do_behaviour(robot_state);
}

void go() {
  motors.leftMotor(255);
  motors.rightMotor(255); //- If motors go opposite ways
  delay(2000);
  robot_state = 1;
}

void halt() {
  motors.brake();
}

void turn() {
  motors.leftMotor(100);
  motors.leftMotor(-100); //positive if motors go same way
  delay(2000);
}

void transition(int state) {
  switch (state)
  {
    case s_drive:
    if (robot_state == 1)
    {
      robot_state == s_stop;
      delay(2000);
      if (robot_state == 0)
      {
        robot_state == 2;
        robot_state == 0;
      }
    }
    break;
  }
}

void do_behaviour(int state) {
  switch (state)
  {
    case s_drive:
    go();
    break;
    
  case s_stop:
    halt();
    break;
    
  case s_turn:
  turn();
  break;
  }
}

void setup() {
  
}
