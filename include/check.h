#ifndef __LOG_CHECK_H__
#define __LOG_CHECK_H__

	#ifdef LOG_NOCHECK
		#define LOG_LOG(level, function, msg) hlog->log(level, function, msg)
	#else
		#define LOG_LOG(level, function, msg) Log::Log::tryLog(level, function, msg)
	#endif

#endif
