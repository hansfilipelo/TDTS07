#include <cassert>
#include <systemc.h>
#include "TrafficLight.h"
#include "monitor.h"
#include "input_gen.h"

int sc_main(int argc, char **argv)
{

  assert(argc == 1);

  sc_set_time_resolution(1,SC_MS);
  sc_time sim_time(66, SC_SEC);

  // Create channels.
  sc_signal<bool> sensor_sig;
  sc_signal<bool> ack_sig;
  sc_signal<bool> request_sig;
  sc_signal<bool> light_sig;

  // Instantiate the modules.
  TrafficLight t_light("Light1");
  Generator gen("Generator");
  Monitor mon("Monitor");

  // Connect the channels to the ports.
  t_light(ack_sig, sensor_sig, light_sig, request_sig);
  gen(ack_sig, sensor_sig);
  mon(light_sig, request_sig);


  // Start the simulation.
  sc_start(sim_time);

  return 0;
}
