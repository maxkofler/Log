#include "log.h"
#include <iostream>

/*
void Log::Log::setLevel(level loglevel){

	if (loglevel > LOG_MAX_LEVEL){
		std::cerr << "!!!! WARNING !!!!!" << std::endl << std::endl;
		std::cerr << "You have set the loglevel to a higher level than this build is optimized for" << std::endl;
		std::cerr << "by the use of LOG_MAX_LEVEL, no messages of the higher levels will appear!" << std::endl << std::endl;
		std::cerr << "!!!! WARNING !!!!!" << std::endl;
	}

	this->_loglevel = loglevel;
}
*/

Log::stream_config* Log::Log::getStreamConf(std::ostream& stream){
	std::ostream* streamPtr = &stream;

	if (_streams.count(streamPtr) <= 0)
		return nullptr;

	return &(_streams[streamPtr]);
}

void Log::Log::setTerminalWidth(uint32_t w){
	_terminal_width = w;
}

uint32_t Log::Log::getTerminalWidth(){
	return _terminal_width;
}
