#ifndef CONTROLLER_H
#define CONTROLLER_H
#define NR_OF_DIRECTIONS 2

#include <systemc.h>

SC_MODULE(Controller) {

    sc_in<bool> request[NR_OF_DIRECTIONS][2];
    sc_out<bool> ack[NR_OF_DIRECTIONS];

    // Members
    int current_direction;
    //sc_time max_time(30, SC_SEC);

    SC_HAS_PROCESS(Controller);
    Controller(sc_module_name name);

    // Member functions
    void ack_method();

};

#endif // CONTROLLER_H
