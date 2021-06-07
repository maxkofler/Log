#include "logbacktrace.h"

std::string LogBacktrace::getTraceStr(size_t id, bool addFun, bool addLevel){
    std::string ret;

    std::vector<logentry_t> trace = getTrace(id);

    for (logentry_t& i : trace){
        ret += i.toString(addFun, addLevel) += "\n";
    }

    return ret;
}

std::string LogBacktrace::getLevelTraceStr(size_t id, int level, bool addFun, bool addLevel){
    std::string ret;

    std::vector<logentry_t> trace = getLevelTrace(id, level);

    for (logentry_t& i : trace){
        ret += i.toString(addFun, addLevel) += "\n";
    }

    return ret;
}