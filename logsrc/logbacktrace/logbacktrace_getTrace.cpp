#include "logbacktrace.h"

#include <iostream>

std::vector<logentry_t> LogBacktrace::getTrace(size_t id){
    if (id >= this->_traces.size()){
        std::cerr << "Invalid attempt to get trace with invalid id: " << id << std::endl;
        //Return an empty vector
        return std::vector<logentry_t>();
    }

    return this->_traces.at(id);
}