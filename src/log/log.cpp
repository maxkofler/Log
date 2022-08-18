#include "log.h"

//The global definition of the hlog instance
Log::Log* hlog = nullptr;

#include <iostream>

Log::Log::Log(level level){
	this->setLevel(level);
	this->_profiles_count = 0;
	this->_profile_stream = nullptr;
	this->_enable_profiling = false;

	#ifdef LOG_NOCHECK
		std::cout << "Log module checks have been disabled, crashes may happen depending on the quality of the software!" << std::endl;
	#endif

	#ifdef LOG_NOMUTEX
		std::cout << "Log mutex has been disabled, logs can overlap!" << std::endl;
	#endif
}

Log::Log::~Log(){
	writeProfileFooter();
}

bool Log::Log::setFeature(feature mode, bool state){
	switch(mode){
		case FEATURE_PRINTFUNNAMES:
			this->_print_function_names = state;

		case FEATURE_PROFILE:
			this->_enable_profiling = state;

		default:
			return false;
	}
	return true;
}
