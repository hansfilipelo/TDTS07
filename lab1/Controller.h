#ifndef CONTROLLER_H
#define CONTROLLER_H
//#define NR_OF_DIRECTIONS 2

#include <systemc.h>

SC_MODULE(Controller) {

    sc_in<bool> request_NS;
    sc_in<bool> request_SN;
    sc_in<bool> request_WE;
    sc_in<bool> request_EW;
    sc_out<bool> ack_NS;
    sc_out<bool> ack_WE;

    // "Internal slots"
    sc_inout<int> current_direction;
    sc_inout<bool> is_acked;

    sc_event timer_event;
    sc_event ack_event;

    SC_HAS_PROCESS(Controller);
    Controller(sc_module_name name);

    // Member functions
    void ack_method();
    void timer_method();
    void request_method();
};

#endif // CONTROLLER_H
