#include "log.h"

std::string Log::p_getIndent(){
    std::string ret = "";
    
    if (_indent){    
        for (size_t i = 0; i < this->_functionStack.size(); i++){
            ret += " ";
        }
    }

    return ret;
}