#include "Controller.h"

Controller::Controller(sc_module_name name)
: sc_module(name)
{
  current_direction = 0;

  for(int i = 0; i < NR_OF_DIRECTIONS; i++)
  {
    ack[i].initialize(false);
  }

  SC_METHOD(request_method);
  dont_initialize();
  for (int i = 0; i < NR_OF_DIRECTIONS ; i++) {
    sensitive << request[i][0];
    sensitive << request[i][1];
  }

  SC_METHOD(timeout_method)
  dont_initialize();
  sensitive << timeout_event;

  SC_METHOD(timeout_method)
  dont_initialize();
  sensitive << ack_event;
}

// -----------------

void Controller::request_method()
{
  if (!is_acked)
  {
    for (size_t i = 0; i < NR_OF_DIRECTIONS; i++)
    {
      if (request[i][0] == true || request[i][1] == true)
      {
        current_direction = i;
        is_acked = true;
        ack_event.notify();
      }
    }
  }
}

// -----------------

void Controller::timeout_method()
{
  int temp_dir = current_direction + 1 % NR_OF_DIRECTIONS;

  for (size_t i = 0; i < NR_OF_DIRECTIONS; i++) {
    if (request[temp_dir][0] == true || request[temp_dir][1] == 1) {
      if (current_direction != temp_dir) {
        ack[current_direction].write(false);
        current_direction = temp_dir;
      }
      ack_event.notify();
      return;
    }
  }

  is_acked = false;
}

// -----------------

void Controller::ack_method()
{
  ack[current_direction].write(true);
  timeout_event.notify(20,SC_SEC);
}
