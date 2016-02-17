#include "input_gen.h"
#include <cassert>

Generator::Generator(sc_module_name name)
: sc_module(name)
{
  SC_THREAD(generate_thread);

  car_N.initialize(false);
  car_S.initialize(false);
  car_W.initialize(false);
  car_E.initialize(false);

}


void Generator::generate_thread()
{
  sc_time max_gen_time = sc_time(Constants::gen_time, SC_SEC);

  while ( sc_time_stamp() < max_gen_time ) {
    car_N.write(rand() % 2 == 1);
    car_S.write(rand() % 2 == 1);
    car_W.write(rand() % 2 == 1);
    car_E.write(rand() % 2 == 1);
    wait(1,SC_SEC);
  }

  car_N.write(false);
  car_S.write(false);
  car_W.write(false);
  car_E.write(false);
}
