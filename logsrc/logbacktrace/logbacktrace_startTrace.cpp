#include "logbacktrace.h"

#include <iostream>

size_t LogBacktrace::startTrace(){
    size_t newID = this->_traces.size();

    std::vector<logentry_t> newTrace;

    this->_traces.push_back(newTrace);

    std::cout << "Started new Backtrace with id " << newID << std::endl;

    return newID;
}