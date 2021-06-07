#ifndef __LOG_ENTRY_H__
#define __LOG_ENTRY_H__

#include <string>

typedef struct logentry_s{

    int level;
    std::string function;
    std::string text;
    
} logentry_t;

#endif