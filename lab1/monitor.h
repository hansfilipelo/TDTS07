#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>

using std::ofstream;

SC_MODULE(Monitor) {
  sc_in<bool> light;
  sc_in<bool> request;

  SC_HAS_PROCESS(Monitor);
  Monitor(sc_module_name name);

  void monitor_thread();
};

#endif // MONITOR_H
