#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name)
  : sc_module(name)
{
  SC_METHOD(monitor_method);
  sensitive << ack_NS << ack_WE;
}

void Monitor::monitor_method()
{
    assert(!(ack_NS.read() && ack_WE.read()));
    cout << sc_time_stamp().to_string() << ": ack_NS " << ack_NS.read() << ", ack_WE " << ack_WE.read() << endl;
}
