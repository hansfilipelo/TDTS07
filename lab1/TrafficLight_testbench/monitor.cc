#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name)
: sc_module(name)
{
  SC_METHOD(monitor_method);
  sensitive << light << request;
}

void Monitor::monitor_method()
{
  cout << sc_time_stamp().to_string() << " Request: " << (int)request.read() <<  ", Light: " << (int)light.read() << ", Ack: " << (int)ack.read() << endl;
}
