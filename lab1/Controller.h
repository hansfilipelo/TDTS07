#ifndef CONTROLLER_H
#define CONTROLLER_H
#define NR_OF_DIRECTIONS 2

#include <systemc.h>

SC_MODULE(Controller) {
    
    sc_in<bool>[NR_OF_DIRECTIONS][2] request;
    sc_out<bool>[NR_OF_DIRECTIONS] ack;
    
    // Members
    int current_direction = 0;
    sc_time max_time(30, SC_SEC);
    
    SC_HAS_PROCESS(Controller);
    Controller(sc_module_name name);
    
    // Member functions
    void ack_method();
    
};

#endif // CONTROLLER_H
