#include "log.h"

#include <iostream>

namespace Log{
	LogFunction::LogFunction(std::string name){
		this->_name = name;
		if (Log::check() && hlog->getLevel() >= FUNCALLS){
			std::cout << "Entered " << this->_name << std::endl;
		}

	}

	LogFunction::~LogFunction(){
		if (Log::check() && hlog->getLevel() >= FUNCALLS){
			std::cout << "Left " << this->_name << std::endl;
		}
	}
}
