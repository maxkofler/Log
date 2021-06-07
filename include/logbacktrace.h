#ifndef __LOG_BACKTRACE_H__
#define __LOG_BACKTRACE_H__

class LogBacktrace;

#include "log.h"
#include "logentry.h"

#include <vector>
#include <string>

class LogBacktrace{

public:
    LogBacktrace();

    /**
     *  Backtracing starts from this function on
     *  @return                             The id for the backtrace
     **/
    size_t                                  startTrace();

    /**
     *  Ends backtracing with this function
     *  @arg    id                          The id for the trace to stop
     **/
    bool                                    stopTrace(size_t id);

    /**
     *  Adds the provided log entry to all backtraces that are active
     *  @arg    entry                       A copy of the entry to push onto traces
     **/
    bool                                    add(logentry_t entry);

private:
    //This is the vector containing all the backtraces[function;name]
    std::vector<std::vector<logentry_t>>    _traces;
};

#endif