#ifndef __LOG_ENTRY_H__
#define __LOG_ENTRY_H__

#include <string>

typedef struct logentry_s{

    int level;
    std::string function;
    std::string text;

    std::string toString(bool addFun, bool addLevel){
        std::string ret = "";
        if (addLevel)
            ret += "(" + std::to_string(level) + ")";
        if (addFun)
            ret += "[" + function + "]: ";
        ret += text;
        return ret;
    }
    
} logentry_t;

#endif