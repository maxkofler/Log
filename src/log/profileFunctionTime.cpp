#include "log.h"

#include <iostream>

static bool alreadyNotedBadStream = false;

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

	/*
	m_OutputStream << "{";
	m_OutputStream << "\"cat\":\"function\",";
	m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
	m_OutputStream << "\"name\":\"" << name << "\",";
	m_OutputStream << "\"ph\":\"X\",";
	m_OutputStream << "\"pid\":0,";
	m_OutputStream << "\"tid\":" << result.ThreadID << ",";
	m_OutputStream << "\"ts\":" << result.Start;
	m_OutputStream << "}";
	*/

	return true;
}
