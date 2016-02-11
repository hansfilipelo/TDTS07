#ifndef MONITOR_H
#define MONITOR_H

#include "constants.h"
#include <systemc.h>
#include <iostream>
#include <string>

SC_MODULE(Monitor) {
  sc_time gen_time;
  sc_time add_time;
  sc_time current_time;

  bool N;
  bool S;
  bool W;
  bool E;

  sc_in<bool> light_N;
  sc_in<bool> light_S;
  sc_in<bool> light_W;
  sc_in<bool> light_E;

  sc_event e;

  SC_HAS_PROCESS(Monitor);
  Monitor(sc_module_name name);

  void monitor_method();
  void e_thread();
};

#endif // MONITOR_H
