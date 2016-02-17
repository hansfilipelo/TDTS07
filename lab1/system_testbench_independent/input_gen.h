#ifndef INPUT_GEN_H
#define INPUT_GEN_H

#include <systemc.h>
#include "../Controller.h"

SC_MODULE(Generator) {
  sc_inout<bool> car_N;
  sc_inout<bool> car_S;
  sc_inout<bool> car_W;
  sc_inout<bool> car_E;

  SC_HAS_PROCESS(Generator);
  Generator(sc_module_name name);

  void generate_thread();
  void print_method();
};

#endif // INPUT_GEN_H
