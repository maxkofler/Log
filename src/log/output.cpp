#include "log.h"

#include <iostream>

#ifdef LOG_NOCHECK
    #warning YOU HAVE DISABLED LOG CHECKS, THIS WILL IMPROVE PERFORMANCE! segfaults can happen if you do not set up your log module correctly!
#endif

namespace Log{
    bool Log::log(level loglevel, std::string function, std::string message){
        #ifndef LOG_NOMUTEX
        this->_m_logging.lock();
        #else
            #warning DISABLED LOG MUTEX, THIS WILL IMPROVE PERFORMANCE! this can lead to overlapping log messages!
        #endif
        if (loglevel <= this->_loglevel){
            if (this->_print_function_names){
                std::cout << "[" << function << "]>>>" << message << std::endl;
            }else{
                std::cout << message << std::endl;
            }
        }
        #ifndef LOG_NOMUTEX
        this->_m_logging.unlock();
        #endif
        return true;
    }

    bool Log::log(level loglevel, std::string function, const char* message){
        return this->log(loglevel, function, std::string(message));
    }
}