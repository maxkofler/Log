#include "log.h"

#include <iostream>

Log::Log::Log(level level){
    this->_loglevel = level;

    #ifdef LOG_NOCHECK
        std::cout << "Log module checks have been disabled, crashes may happen depending on the quality of the software!" << std::endl;
    #endif

    #ifdef LOG_NOMUTEX
        std::cout << "Log mutex has been disabled, logs can overlap!" << std::endl;
    #endif
}

bool Log::Log::setFeature(feature mode, bool state){
    switch(mode){
        case FEATURE_PRINTFUNNAMES:
            this->_print_function_names = state;

        default:
            return false;
    }
    return true;
}