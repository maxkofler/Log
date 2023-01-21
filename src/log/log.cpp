#include "log.h"

//The global definition of the hlog instance
Log::Log* hlog = nullptr;

#include <iostream>

Log::Log::Log(){
	this->_profiles_count = 0;
	this->_profile_stream = nullptr;
	this->_enable_profiling = false;
}

Log::Log::~Log(){
	writeProfileFooter();
}

bool Log::Log::setFeature(feature mode, bool state){
	switch(mode){

		case FEATURE_PROFILE:
			this->_enable_profiling = state;
			break;

		default:
			return false;
	}
	return true;
}
