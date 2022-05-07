#include "log.h"

#include <iostream>

namespace Log{
	LogFunction::LogFunction(std::string name){
		this->_name = name;
		if (Log::check() && hlog->getLevel() >= FUNCALLS){
			std::cout << "Entered " << this->_name << std::endl;
		}

		#ifdef LOG_ENABLE_PROFILING
		_profileProbe = ProfileProbe(name);
		_profileProbe.start();
		#endif
	}

	LogFunction::~LogFunction(){
		#ifdef LOG_ENABLE_PROFILING
		_profileProbe.stop();
		#endif

		if (Log::check() && hlog->getLevel() >= FUNCALLS){
			std::cout << "Left " << this->_name << std::endl;
		}

		#ifdef LOG_ENABLE_PROFILING
		hlog->profileFunctionTime(_profileProbe.get());
		#endif
	}
}
