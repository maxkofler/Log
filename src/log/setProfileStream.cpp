#include "log.h"

#include <fstream>
#include <iostream>

bool Log::Log::setProfileStream(std::ostream* stream){

	if (stream == nullptr){
		std::cerr << "[Log] Profile stream is NULL" << std::endl;
		return false;
	}

	if (stream->bad()){
		std::cerr << "[Log] Profile stream is bad" << std::endl;
		return false;
	}

	_profile_stream = stream;

	return true;
}
