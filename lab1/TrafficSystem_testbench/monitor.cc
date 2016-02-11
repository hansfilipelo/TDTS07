#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name)
  : sc_module(name)
{
  SC_METHOD(monitor_method);
  sensitive << light_N << light_S << light_W << light_E;
}

void Monitor::monitor_method()
{
  assert( !((light_N.read() || light_S.read()) && (light_W.read() || light_E.read())) );
}
