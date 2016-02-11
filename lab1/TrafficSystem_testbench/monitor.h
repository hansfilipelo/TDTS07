#ifndef MONITOR_H
#define MONITOR_H

#include "constants.h"
#include <systemc.h>

using std::ofstream;

SC_MODULE(Monitor) {
  sc_in<bool> light_N;
  sc_in<bool> light_S;
  sc_in<bool> light_W;
  sc_in<bool> light_E;

  sc_in<bool> car_N;
  sc_in<bool> car_S;
  sc_in<bool> car_W;
  sc_in<bool> car_E;

  SC_HAS_PROCESS(Monitor);
  Monitor(sc_module_name name);

  void monitor_thread();
};

#endif // MONITOR_H
