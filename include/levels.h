#ifndef __LOG_LEVELS_H__
#define __LOG_LEVELS_H__

	#include "platform.h"
	#include "check.h"

	#if LOG_MAX_LEVEL >= 0
		#define LOGUE(msg) LOG_LOG(Log::UE, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGUE(msg)
	#endif

	#if LOG_MAX_LEVEL >= 1
		#define LOGUW(msg) LOG_LOG(Log::UW, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGUW(msg)
	#endif

	#if LOG_MAX_LEVEL >= 2
		#define LOGU(msg) LOG_LOG(Log::U, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGU(msg)
	#endif

	#if LOG_MAX_LEVEL >= 3
		#define LOGE(msg) LOG_LOG(Log::E, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGE(msg)
	#endif

	#if LOG_MAX_LEVEL >= 4
		#define LOGW(msg) LOG_LOG(Log::W, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGW(msg)
	#endif

	#if LOG_MAX_LEVEL >= 5
		#define LOGI(msg) LOG_LOG(Log::I, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGI(msg)
	#endif

	#if LOG_MAX_LEVEL >= 6
		#define LOGP(msg) LOG_LOG(Log::P, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGP(msg)
	#endif

	#if LOG_MAX_LEVEL >= 7
		#define LOGDE(msg) LOG_LOG(Log::DE, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGDE(msg)
	#endif

	#if LOG_MAX_LEVEL >= 8
		#define LOGDW(msg) LOG_LOG(Log::DW, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGDW(msg)
	#endif

	#if LOG_MAX_LEVEL >= 9
		#define LOGDI(msg) LOG_LOGD(Log::DI, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGDI(msg)
	#endif

	#if LOG_MAX_LEVEL >= 10
		#define LOGD(msg) LOG_LOG(Log::D, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGD(msg)
	#endif

	#if LOG_MAX_LEVEL >= 11
		#define LOGAPI(msg) LOG_LOG(Log::API, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGAPI(msg)
	#endif

	#if LOG_MAX_LEVEL >= 12
		#define LOGF(msg) LOG_LOG(Log::F, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGF(msg)
	#endif

	#if LOG_MAX_LEVEL >= 13
		#define LOGN(msg) LOG_LOG(Log::N, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGN(msg)
	#endif

	#if LOG_MAX_LEVEL >= 14
		#define LOGIO(msg) LOG_LOG(Log::IO, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGIO(msg)
	#endif

	#if LOG_MAX_LEVEL >= 15
		#define LOGMEM(msg) LOG_LOG(Log::MEM, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGMEM(msg)
	#endif

	#if LOG_MAX_LEVEL >= 16
		#define LOGFUNCALLS(msg) LOG_LOG(Log::FUNCALLS, LOG_FUNCTION_MACRO, msg)
	#else
		#define LOGFUNCALLS(msg)
	#endif

#endif
