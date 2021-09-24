#include "log.h"

Log::level Log::Log::getLevel(){
    return this->_loglevel;
}

void Log::Log::setLevel(level loglevel){
    this->_loglevel = loglevel;
}