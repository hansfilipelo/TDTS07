#include <cassert>
#include <systemc.h>
#include "../Controller.h"
#include "monitor.h"
#include "input_gen.h"

int sc_main(int argc, char **argv)
{

  assert(argc == 1);

  sc_set_time_resolution(1,SC_SEC);
  sc_time sim_time(100, SC_SEC);

  // Create channels.
  sc_signal<bool> request_NS_sig;
  sc_signal<bool> request_SN_sig;
  sc_signal<bool> request_WE_sig;
  sc_signal<bool> request_EW_sig;
  sc_signal<bool> ack_NS_sig;
  sc_signal<bool> ack_WE_sig;

  // Instantiate the modules.
  Controller contr("Controller");
  Generator gen("Generator");
  Monitor mon("Monitor");

  // Connect the channels to the ports.
  contr(request_NS_sig, request_SN_sig, request_WE_sig, request_EW_sig, ack_NS_sig, ack_WE_sig);
  gen(request_NS_sig, request_SN_sig, request_WE_sig, request_EW_sig);
  mon(ack_NS_sig, ack_WE_sig);


  // Start the simulation.
  sc_start(sim_time);

  return 0;
}
