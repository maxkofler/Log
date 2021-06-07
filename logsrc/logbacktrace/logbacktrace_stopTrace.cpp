#include "logbacktrace.h"

#include <iostream>

bool LogBacktrace::stopTrace(size_t id){
    //Check if the trace is valid
    if (id >= this->_traces.size()){
        return false;
    }

    this->_traces.erase(this->_traces.begin() + id);

    std::cout << "Stopped backtrace with id " << id << std::endl;

    return true;
}