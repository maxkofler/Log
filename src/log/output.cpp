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

				//If there are any progresses, print a newline and cursor up
				if (stream.second.enable_progress){
					ss_output << "\n";
					for (uint32_t i = 0; i < _progresses.size()+1; i++)
						ss_output << "\033[F";
				}

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

				//If a progress is displayed, clear the line of the logged message
				if (stream.second.enable_progress)
					ss_output << "\033[2K";

				ss_output << message << std::endl;

				#ifndef LOG_NOCOLOR
				//Terminate color information
				if (stream.second.enable_colors)
					ss_output << "\033[0m";
				#endif

				//If there are progresses to print, update them now
				if (stream.second.enable_progress){
					for (uint32_t i = _progresses.size(); i > 0; i--){
						_progresses[i-1]->_m_bar.lock();
						ss_output << _progresses[i-1]->_bar << "\n";
						_progresses[i-1]->_m_bar.unlock();
					}
				}

				(*stream.first) << ss_output.str();

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
