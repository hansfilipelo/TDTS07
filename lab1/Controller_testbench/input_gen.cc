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

}


void Generator::generate_thread()
{
  for (;;) {
    printf("Hello from generate_thread\n");
    request_NS.write(rand() % 2 == 1);
    request_SN.write(rand() % 2 == 1);
    request_WE.write(rand() % 2 == 1);
    request_EW.write(rand() % 2 == 1);
    printf("Request_NS = %i. Request_SN = %i. Request_WE = %i. Request_EW = %i.\n", \
    request_NS.read(), request_SN.read(), request_WE.read(), request_EW.read());
    wait(10,SC_SEC);
  }
}
