// Drive Stop

#include <RedBot.h>

RedBotMotors motors;

#define s_drive 0
#define s_stop 1
int robot_state = 0;

void loop() {
  transition(robot_state);
  do_behaviour(robot_state);
}

void go() {
  motors.leftMotor(255);
  motors.rightMotor(255); //- If motors go opposire ways
  delay(2000);
  robot_state = 1;
}

void halt() {
  motors.brake();
}

void transition(int state) {
  switch (state)
  {
    case s_drive:
    if (robot_state == 1)
    {
      robot_state == s_stop;
    }
    break;
  }
}

void do_behaviour(int state) {
  switch (state)
  {
    case s_drive:
    {
    go();
    break;
    }
  case s_stop:
    halt();
    break;
  }
}

void setup() {
  
}
