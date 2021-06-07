#include "logbacktrace.h"

bool LogBacktrace::add(logentry_t entry){
    for (auto& i : this->_traces)
        i.push_back(entry);

    return true;
}