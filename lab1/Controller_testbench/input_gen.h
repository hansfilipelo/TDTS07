#ifndef INPUT_GEN_H
#define INPUT_GEN_H

#include <systemc.h>
#include "../Controller.h"

SC_MODULE(Generator) {
  sc_inout<bool> request_NS;
  sc_inout<bool> request_SN;
  sc_inout<bool> request_WE;
  sc_inout<bool> request_EW;

  SC_HAS_PROCESS(Generator);
  Generator(sc_module_name name);

  void generate_thread();
  void print_method();
};

#endif // INPUT_GEN_H
