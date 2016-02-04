#ifndef INPUT_GEN_H
#define INPUT_GEN_H

#include <systemc.h>
#include <fstream>

using std::ifstream;

SC_MODULE(Generator) {
  sc_out<bool> ack;
  sc_out<bool> sensor;

  SC_HAS_PROCESS(Generator);
  Generator(sc_module_name name);

  void ack_generate_thread();
  void sensor_generate_thread();
};

#endif // INPUT_GEN_H
