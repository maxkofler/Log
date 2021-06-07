#include "logbacktrace.h"

#include <iostream>

std::vector<logentry_t> LogBacktrace::getLevelTrace(size_t id, int level){
    if (id >= this->_traces.size()){
        std::cerr << "Invalid attempt to get trace with invalid id: " << id << std::endl;
        //Return an empty vector
        return std::vector<logentry_t>();
    }

    std::vector<logentry_t> ret;

    for (logentry_t& i : this->_traces.at(id)){
        if (i.level <= level)
            ret.push_back(i);
    }

    return ret;
}