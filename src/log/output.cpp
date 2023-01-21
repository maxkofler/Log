#include "log.h"

#include <iostream>
#include <sstream>

namespace Log{
	bool Log::log(level loglevel, std::string function, std::string message){
		if (loglevel <= this->_loglevel){
			#ifndef LOG_NOMUTEX
				this->_m_logging.lock();
			#endif

			std::stringstream msg;

			#ifndef LOG_NOCOLOR
				if (_enable_colors){
					if (loglevel == E || loglevel == UE)
						msg << "\033[31;1m";
					if (loglevel == W || loglevel == UW)
						msg << "\033[33;1m";
				}
			#endif

			if (this->_print_function_names)
				msg << "[" << function << "]>>>";

			msg << message;

			#ifndef LOG_NOCOLOR
				if (_enable_colors)
					msg << "\033[0m";
			#endif

			std::cout << msg.str() << std::endl;

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
