#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name)
  : sc_module(name)
{
  SC_THREAD(monitor_thread);
}

void Monitor::monitor_thread()
{
  wait(1,SC_SEC);
  for(;;)
  {
    
    wait(5,SC_SEC);
  }
}
