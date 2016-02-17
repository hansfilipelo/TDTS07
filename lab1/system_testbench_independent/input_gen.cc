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

  SC_METHOD(print_method);
  sensitive << car_N << car_S << car_W << car_E;
}

// -----------------------------

void Generator::generate_thread()
{

  wait(5,SC_SEC);

  car_W.write(true);

  wait(5,SC_SEC);

  car_W.write(false);

  wait(5,SC_SEC);

  car_E.write(true);

  wait(5,SC_SEC);

  car_E.write(false);

}

// -----------------------------

void Generator::print_method()
{
  cout << sc_time_stamp().to_string() << ": car_N " << car_N.read() << ", car_S " << car_S.read() \
  << ", car_W " << car_W.read() << ", car_E " << car_E.read() << endl;
}
