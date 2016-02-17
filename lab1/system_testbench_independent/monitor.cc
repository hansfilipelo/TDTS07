#include <cassert>
#include "monitor.h"

using namespace std;

Monitor::Monitor(sc_module_name name)
: sc_module(name)
{
  SC_METHOD(monitor_method);
  sensitive << light_N << light_S << light_W << light_E;

}

void Monitor::monitor_method()
{
  cout << sc_time_stamp().to_string() << ": light_N " << light_N.read() << ", light_S " << light_S.read() \
  << ", light_W " << light_W.read() << ", light_E " << light_E.read() << endl;
}
