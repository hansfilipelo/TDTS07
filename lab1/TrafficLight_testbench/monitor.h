#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>

using std::ofstream;

SC_MODULE(Monitor) {
  sc_in<bool> light;
  sc_in<bool> request;
  sc_in<bool> ack;

  SC_HAS_PROCESS(Monitor);
  Monitor(sc_module_name name);

  void monitor_method();
};

#endif // MONITOR_H
