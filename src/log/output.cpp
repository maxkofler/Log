#include "log.h"

#include <iostream>

namespace Log{
    bool Log::log(level loglevel, std::string function, std::string message){
        std::cout << "[" << function << ":" << loglevel << "]>>>" << message << std::endl;
        return true;
    }

    bool Log::log(level loglevel, std::string function, const char* message){
        std::cout << "[" << function << ":" << loglevel << "]>>>" << message << std::endl;
        return true;
    }
}