#include "Controller.h"

Controller::Controller(sc_module_name name)
: sc_module(name)
{
  current_direction = 0;

  for(int i = 0; i < NR_OF_DIRECTIONS; i++)
  {
    ack[i].initialize(false);
  }

  SC_METHOD(ack_method);
  dont_initialize();
  for (int i = 0; i < NR_OF_DIRECTIONS ; i++) {
    sensitive << request[i][0];
    sensitive << request[i][1];
  }
  // sensitive << max_time_event
}

void Controller::ack_method()
{
  int former_direction = current_direction;

  for (int i = 0; i < NR_OF_DIRECTIONS; i++) {

    if (request[current_direction][0] || request[current_direction][1] ) // ) && !max_time_event)
    {
      if( former_direction != current_direction)
      {
        ack[former_direction]->write(false);
      }
      ack[current_direction]->write(true);
      break;
    }
    else
    {
      ack[current_direction]->write(false);
      current_direction = (current_direction + 1) % NR_OF_DIRECTIONS;
    }

  }
}
