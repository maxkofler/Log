#include "log.h"

//The global definition of the hlog instance
Log::Log* hlog = nullptr;

#include <iostream>

Log::Log::Log(level level){
	this->setLevel(level);
	this->_profiles_count = 0;
	this->_profile_stream = nullptr;
	this->_enable_profiling = false;
}

Log::Log::~Log(){
	writeProfileFooter();
}

bool Log::Log::setFeature(feature mode, bool state){
	switch(mode){
		case FEATURE_PRINTFUNNAMES:
			this->_print_function_names = state;
			break;

		case FEATURE_PROFILE:
			this->_enable_profiling = state;
			break;

		case FEATURE_COLOR:
			this->_enable_colors = state;
			break;

		default:
			return false;
	}
	return true;
}
