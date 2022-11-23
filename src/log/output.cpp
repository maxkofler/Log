#include "log.h"

#include <iostream>

namespace Log{
	bool Log::log(level loglevel, std::string function, std::string message){

		//Go through every stream
		for (const auto &stream : _streams){

			if (stream.second.loglevel <= this->_loglevel){
				#ifndef LOG_NOMUTEX
					this->_m_logging.lock();
				#endif

				if (stream.second.print_function_names){
					(*stream.first) << "[" << function << "]>>>" << message << std::endl;
				}else{
					(*stream.first) << message << std::endl;
				}

				#ifndef LOG_NOMUTEX
					this->_m_logging.unlock();
				#endif
			}
		}
		return true;
	}

	bool Log::log(level loglevel, std::string function, const char* message){
		return this->log(loglevel, function, std::string(message));
	}
}
