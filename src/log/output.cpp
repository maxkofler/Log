#include "log.h"

#include <iostream>

namespace Log{
	bool Log::log(level loglevel, std::string function, std::string message){
		if (loglevel <= this->_loglevel){
			#ifndef LOG_NOMUTEX
				this->_m_logging.lock();
			#endif


			if (this->_print_function_names){
				std::cout << "[" << function << "]>>>" << message << std::endl;
			}else{
				std::cout << message << std::endl;
			}

			#ifndef LOG_NOMUTEX
				this->_m_logging.unlock();
			#endif
		}
		return true;
	}

	bool Log::log(level loglevel, std::string function, const char* message){
		return this->log(loglevel, function, std::string(message));
	}
}
