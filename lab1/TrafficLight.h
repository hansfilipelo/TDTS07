#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <systemc.h>

SC_MODULE(TrafficLight) {
  sc_in<bool> ack;
  sc_in<bool> sensor;

  sc_inout<bool> light;
  sc_out<bool> request;
  sc_event unhandled_vehicle_change;

  // Members
  bool unhandled_vehicle;

  SC_HAS_PROCESS(TrafficLight);
  TrafficLight(sc_module_name name);

  // Member functions
  void sensor_method();
  void on_off_method();
};

#endif // TRAFFIC_LIGHT_H
