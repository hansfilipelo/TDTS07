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
    printf("Hello from monitor_method!\n");
    printf("Ack_NS = %i. Ack_WE = %i.\n", ack_NS.read(), ack_WE.read());
    assert(!(ack_NS.read() && ack_WE.read()));
}
