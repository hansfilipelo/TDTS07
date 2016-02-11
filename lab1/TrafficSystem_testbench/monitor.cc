#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name)
  : sc_module(name)
{
  SC_THREAD(monitor_thread);
}

void Monitor::monitor_thread()
{
  for (;;) {
    assert( !((light_N.read() || light_S.read()) && (light_W.read() || light_E.read())) );
  }
}
