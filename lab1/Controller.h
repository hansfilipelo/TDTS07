#ifndef CONTROLLER_H
#define CONTROLLER_H
#define NR_OF_DIRECTIONS 2

#include <systemc.h>

SC_MODULE(Controller) {

    sc_in<bool> request[NR_OF_DIRECTIONS][2];
    sc_out<bool> ack[NR_OF_DIRECTIONS];

    sc_event timeout_event;
    sc_event ack_event;
    sc_mutex state_lock;

    // Members
    int current_direction = 0;
    bool is_acked = false;

    SC_HAS_PROCESS(Controller);
    Controller(sc_module_name name);

    // Member functions
    void ack_method();
    void timeout_method();
    void request_method();
};

#endif // CONTROLLER_H
