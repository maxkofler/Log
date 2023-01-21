#include "log.h"

#include <iostream>
#include <sstream>

namespace Log{
	bool Log::log(level loglevel, std::string function, std::string message){

		//Go through every stream
		for (const auto &stream : _streams){

			if (loglevel <= stream.second.loglevel){
				#ifndef LOG_NOMUTEX
					this->_m_logging.lock();
				#endif

				//A temporary buffer
				std::stringstream ss_output;

				#ifndef LOG_NOCOLOR
				//Add the color information
				if (stream.second.enable_colors)
					if (loglevel == E || loglevel == UE)
						ss_output << "\033[31;1m";
					if (loglevel == W || loglevel == UW)
						ss_output << "\033[33;1m";

				if (stream.second.print_function_names)
					ss_output << "[" << function << "]>>>";
				#endif

				ss_output << message;

				#ifndef LOG_NOCOLOR
				//Terminate color information
				if (stream.second.enable_colors)
					ss_output << "\033[0m";
				#endif

				(*stream.first) << ss_output.str() << std::endl;

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
