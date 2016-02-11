#include <cassert>
#include <systemc.h>
#include "../Controller.h"
#include "../TrafficLight.h"
#include "monitor.h"
#include "input_gen.h"

int sc_main(int argc, char **argv)
{

  assert(argc == 1);

  // Can't run after you've set non-zero time constants
  // http://workspace.accellera.org/Discussion_Forums/systemc-forum/archive/msg?list_name=systemc-forum&monthdir=201105&msg=msg00001.html
  sc_set_time_resolution(1, SC_SEC);

  sc_time sim_time = sc_time(Constants::gen_time + Constants::add_time, SC_SEC);

  // Create channels.
  // Incomming cars
  sc_signal<bool> car_N_sig;
  sc_signal<bool> car_S_sig;
  sc_signal<bool> car_W_sig;
  sc_signal<bool> car_E_sig;

  // Out signal from lights
  sc_signal<bool> light_N_sig;
  sc_signal<bool> light_S_sig;
  sc_signal<bool> light_W_sig;
  sc_signal<bool> light_E_sig;

  // Requests from lights to controller
  sc_signal<bool> req_N_sig;
  sc_signal<bool> req_S_sig;
  sc_signal<bool> req_W_sig;
  sc_signal<bool> req_E_sig;

  // Acks from controller to lights
  sc_signal<bool> ack_WE_sig;
  sc_signal<bool> ack_NS_sig;

  // Instantiate the modules.
  Controller contr("Controller");

  TrafficLight light_n("North");
  TrafficLight light_s("South");
  TrafficLight light_w("West");
  TrafficLight light_e("East");

  Generator gen("Generator");
  Monitor mon("Monitor");

  // Connect the channels to the ports.
  light_n(ack_NS_sig, car_N_sig, light_N_sig, req_N_sig);
  light_s(ack_NS_sig, car_S_sig, light_S_sig, req_S_sig);
  light_w(ack_WE_sig, car_W_sig, light_W_sig, req_W_sig);
  light_e(ack_WE_sig, car_E_sig, light_E_sig, req_E_sig);

  contr(req_N_sig, req_S_sig, req_W_sig, req_E_sig, ack_NS_sig, ack_WE_sig);

  gen(car_N_sig, car_S_sig, car_W_sig, car_E_sig);
  mon(light_N_sig, light_S_sig, light_W_sig, light_E_sig, car_N_sig, car_S_sig, car_W_sig, car_E_sig);


  // Start the simulation.
  sc_start(sim_time);

  return 0;
}
