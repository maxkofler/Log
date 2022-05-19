#include "log.h"

#include <iostream>
#include <algorithm>

static bool alreadyNotedBadStream = false;

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

	writeProfileHeader();

	return true;
}

bool Log::Log::profileFunctionTime(struct function_profile res){

	if (!_enable_profiling)
		return true;

	if (_profile_stream == nullptr)
		return false;

	if (_profile_stream->bad()){
		if (!alreadyNotedBadStream){
			std::cerr << "[Log] Tried to output profile to bad output stream" << std::endl;
			alreadyNotedBadStream = true;
		}
		return false;
	}

	if (_profiles_count > 0)
		*_profile_stream << ",\n";

	std::replace(res.funName.begin(), res.funName.end(), '"', '\'');

	*_profile_stream << "{\n";
	*_profile_stream << "\t\"cat\":\"function\",\n";
	*_profile_stream << "\t\"dur\":" << (res.end - res.start) << ",\n";
	*_profile_stream << "\t\"name\":\"" << res.funName << "\",\n";
	*_profile_stream << "\t\"ph\":\"X\",\n";
	*_profile_stream << "\t\"pid\":" << res.procID << ",\n";
	*_profile_stream << "\t\"tid\":" << res.threadID << ",\n";
	*_profile_stream << "\t\"ts\":" << res.start << "\n";
	*_profile_stream << "}";

	_profile_stream->flush();

	_profiles_count++;

	return true;
}

void Log::Log::writeProfileHeader(){
	if (!_enable_profiling)
		return;

	if (_profile_stream == nullptr)
		return;

	if (_profile_stream->bad()){
		if (!alreadyNotedBadStream){
			std::cerr << "[Log] Tried to output profile to bad output stream" << std::endl;
			alreadyNotedBadStream = true;
		}
		return;
	}

	*_profile_stream << "{\"otherData\": {},\"traceEvents\":[" << std::endl;
}

void Log::Log::writeProfileFooter(){
	if (!_enable_profiling)
		return;

	if (_profile_stream == nullptr)
		return;

	if (_profile_stream->bad()){
		if (!alreadyNotedBadStream){
			std::cerr << "[Log] Tried to output profile to bad output stream" << std::endl;
			alreadyNotedBadStream = true;
		}
		return;
	}

	*_profile_stream << "]}" << std::endl;
}
