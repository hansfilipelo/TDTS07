#include "Controller.h"

Controller::Controller(sc_module_name name)
: sc_module(name)
{
  current_direction = 0;

  ack_NS.initialize(false);
  ack_WE.initialize(false);

  SC_METHOD(request_method);
  dont_initialize();
  sensitive << request_NS << request_SN << request_WE << request_EW;

  SC_METHOD(timeout_method)
  dont_initialize();
  sensitive << timeout_event;

  SC_METHOD(ack_method)
  dont_initialize();
  sensitive << ack_event;
}

// -----------------

void Controller::request_method()
{
  if (!is_acked)
  {

    if (request_NS.read() || request_SN.read())
    {
      current_direction = 0;
      is_acked = true;
      ack_event.notify();
    }
    else if (request_WE.read() || request_EW.read())
    {
      current_direction = 1;
      is_acked = true;
      ack_event.notify();
    }

  }
}

// -----------------

void Controller::timeout_method()
{
  if (current_direction == 0)
  {
    if(request_WE.read() || request_EW.read())
    {
      ack_NS.write(false);
      ack_WE.write(true);
      current_direction = 1;
      ack_event.notify();
    }
    else if(request_NS.read() || request_SN.read())
    {
      ack_event.notify();
    }
    else
    {
      is_acked = false;
    }
  }
  else if (current_direction == 1)
  {
    if(request_NS.read() || request_SN.read())
    {
      ack_WE.write(false);
      ack_NS.write(true);
      current_direction = 0;
      ack_event.notify();
    }
    else if(request_WE.read() || request_EW.read())
    {
      ack_event.notify();
    }
    else
    {
      is_acked = false;
    }

  }
}

// -----------------

void Controller::ack_method()
{
  timeout_event.notify(20,SC_SEC);
}
