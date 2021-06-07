#ifndef __LOG_BACKTRACE_H__
#define __LOG_BACKTRACE_H__

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

    /**
     *  Returns a trace according to the provided ID
     **/
    std::vector<logentry_t>                 getTrace(size_t id);

    /**
     *  Returns a trace with the specified ID and upper level:
     *      level = I
     *      
     *      included:   I, W, E
     **/
    std::vector<logentry_t>                 getLevelTrace(size_t id, int level);

    /**
     *  Do the same as the upper two functions but convert the result into a string
     **/
    std::string                             getTraceStr(size_t id, bool addFun, bool addLevel);
    std::string                             getLevelTraceStr(size_t id, int level, bool addFun, bool addLevel);

private:
    //This is the vector containing all the backtraces[function;name]
    std::vector<std::vector<logentry_t>>    _traces;
};

#endif