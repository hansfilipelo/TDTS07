#include "TrafficLight.h"

TrafficLight::TrafficLight(sc_module_name name)
: sc_module(name)
{
    light.initialize(false);
    request.initialize(false);

    SC_METHOD(sensor_method);
    dont_initialize();
    sensitive << sensor << light;

    SC_METHOD(on_off_method);
    dont_initialize();
    sensitive << ack;
}

// ----------------

void TrafficLight::sensor_method()
{
    bool cars_in_queue = sensor->read();
    bool traffic_light = light->read();

    if (traffic_light) {
        unhandled_vehicle = false;
    }
    else if(!unhandled_vehicle && !traffic_light)
    {
        unhandled_vehicle = cars_in_queue;
    }

    request->write(unhandled_vehicle);

}


// ----------------

void TrafficLight::on_off_method()
{
    bool ack_in = ack->read();
    bool light_out = ack_in && unhandled_vehicle;

    light->write(light_out);
}
