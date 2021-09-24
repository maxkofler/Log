#include "log.h"

bool Log::Log::check(){
    if (hlog == nullptr)
        return false;
    return true;
}