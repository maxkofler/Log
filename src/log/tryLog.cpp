#include "log.h"

#include <iostream>

static bool errorPlot = false;

bool Log::Log::tryLog(level loglevel, std::string function, std::string message){
	if (!check() && !errorPlot){
		errorPlot = true;
		std::cerr << "!!!!!!!!!!!!!!!!!!!!" << std::endl << std::endl;
		std::cerr << "YOUR LOG MODULE WAS NOT SET UP, NO LOG MESSAGES WILL APPEAR!" << std::endl << std::endl;
		std::cerr << "!!!!!!!!!!!!!!!!!!!!" << std::endl;
		return false;
	}else{
		hlog->log(loglevel, function, message);
	}
	return true;
}
