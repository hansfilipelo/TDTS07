#include "input_gen.h"
#include <cassert>

Generator::Generator(sc_module_name name)
: sc_module(name)
{
  SC_THREAD(generate_thread);

  request_NS.initialize(false);
  request_SN.initialize(false);
  request_WE.initialize(false);
  request_EW.initialize(false);

  SC_METHOD(print_method);
  sensitive << request_NS << request_SN << request_WE << request_EW;

}

// -------------

void Generator::generate_thread()
{
  for (;;) {
    request_NS.write(rand() % 2 == 1);
    request_SN.write(rand() % 2 == 1);
    request_WE.write(rand() % 2 == 1);
    request_EW.write(rand() % 2 == 1);
    wait(10,SC_SEC);
  }
}

// -------------

void Generator::print_method()
{
  cout << sc_time_stamp().to_string() << " req_NS: "<< request_NS.read() << ", req_SN: " << request_SN.read() << ", req_WE: " << request_WE.read() << ", req_EW: " << request_EW.read() << endl;
}
