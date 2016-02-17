#include "input_gen.h"
#include <cassert>

Generator::Generator(sc_module_name name)
  : sc_module(name)
{
  SC_THREAD(ack_generate_thread);
  SC_THREAD(sensor_generate_thread);

  ack.initialize(false);
  sensor.initialize(false);
}


void Generator::ack_generate_thread()
{
  bool ack_local;

  wait(10, SC_SEC); // At time 10
  ack_local = true;
  ack->write(ack_local);

  wait(20, SC_SEC); // At time 30
  ack_local = false;
  ack->write(ack_local);

  wait(5, SC_SEC); // At time 35
  ack_local = true;
  ack->write(ack_local);

  wait(20, SC_SEC); // at time 55
  ack_local = false;
  ack->write(ack_local);

}

void Generator::sensor_generate_thread()
{
  bool sensor_local;

  wait(5, SC_SEC); // At time 5
  sensor_local = true;
  sensor->write(sensor_local);

  wait(10, SC_SEC); // At time 15
  sensor_local = false;
  sensor->write(sensor_local);

  wait(25, SC_SEC); // At time 40
  sensor_local = true;
  sensor->write(sensor_local);

  wait(20, SC_SEC); // At time 60
  sensor_local = false;
  sensor->write(sensor_local);

}
