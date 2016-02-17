#include "TrafficLight.h"

TrafficLight::TrafficLight(sc_module_name name)
: sc_module(name)
{
  light.initialize(false);
  request.initialize(false);
  unhandled_vehicle.initialize(false);

  SC_METHOD(sensor_method);
  dont_initialize();
  sensitive << sensor << light;

  SC_METHOD(on_off_method);
  dont_initialize();
  sensitive << ack << unhandled_vehicle_change;
}

// ----------------

void TrafficLight::sensor_method()
{
  bool cars_in_queue = sensor->read();
  bool traffic_light = light->read();

  if (traffic_light) {
    unhandled_vehicle->write(false);
  }
  else if(!unhandled_vehicle->read() && !traffic_light)
  {
    unhandled_vehicle->write(cars_in_queue);
    unhandled_vehicle_change.notify(SC_ZERO_TIME);
  }

  request->write(unhandled_vehicle->read());

}


// ----------------

void TrafficLight::on_off_method()
{
  bool ack_in = ack->read();
  bool light_out = ack_in && unhandled_vehicle->read();

  light->write(light_out);
}
