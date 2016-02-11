#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name)
  : sc_module(name)
{
  SC_METHOD(monitor_method);
  sensitive << light_N << light_S << light_W << light_E;

  gen_time = sc_time(Constants::gen_time, SC_SEC);
  add_time = sc_time(Constants::add_time, SC_SEC);
  N = false;
  S = false;
  W = false;
  E = false;
}

void Monitor::monitor_method()
{
  current_time = sc_time_stamp();

  assert( !((light_N.read() || light_S.read()) && (light_W.read() || light_E.read())) );


  if ( current_time > gen_time ) {
    if ( light_N.read() ) {
      N = true;
    }
    if ( light_S.read() ) {
      S = true;
    }
    if ( light_W.read() ) {
      W = true;
    }
    if ( light_E.read() ) {
      E = true;
    }

    if ( current_time > gen_time+add_time-sc_time(2,SC_SEC) ) {
      assert( N && S && W && E );
    }
  }

}
