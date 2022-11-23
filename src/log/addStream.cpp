/**
 * @file		log/addStream.cpp
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		The implementation of Log::addStream()
 * @copyright	Copyright (c) 2022
 */
#include "log.h"

bool Log::Log::addStream(std::ostream& stream, stream_config conf){
	std::ostream* streamPtr = &stream;

	if (_streams.count(streamPtr) > 0)
		return false;

	_streams[streamPtr] = conf;

	return true;
}
