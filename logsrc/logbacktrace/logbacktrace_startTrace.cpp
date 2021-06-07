#include "logbacktrace.h"

size_t LogBacktrace::startTrace(){
    size_t newID = this->_traces.size();

    std::vector<logentry_t> newTrace;

    this->_traces.push_back(newTrace);

    return newID;
}