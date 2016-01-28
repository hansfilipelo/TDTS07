#include "TrafficLight.h"

TrafficLight::TrafficLight(sc_module_name name)
  : sc_module(name)
{
  light.initialize(0);
  request.initialize(0);

  SC_METHOD(sensor_method);
  dont_initialize();
  sensitive << clock.pos();

  SC_METHOD(sensor_method);
  dont_initialize();
  sensitive << clock.pos();

  SC_METHOD(on_off_method);
  dont_initialize();
  sensitive << clock.pos();
}

// ----------------

void TrafficLight::sensor_method()
{
  bool cars_in_queue = sensor->read();
  bool traffic_light = light->read();

  unhandled_vehicle = cars_in_queue && !traffic_light;
}

// ----------------

void TrafficLight::request_method()
{
  request->write(unhandled_vehicle);
}

// ----------------

void TrafficLight::on_off_method()
{
  bool ack_in = ack->read();
  bool light_out = ack_in && unhandled_vehicle;

  light->write(light_out);
}
