#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>

SC_MODULE(Monitor) {
  sc_in<bool> ack_NS;
  sc_in<bool> ack_WE;

  SC_HAS_PROCESS(Monitor);
  Monitor(sc_module_name name);

  void monitor_method();
};

#endif // MONITOR_H
