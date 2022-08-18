#ifndef __LOG_PLATFORM_H__
#define __LOG_PLATFORM_H__

	#ifdef WIN32
		#define LOG_FUNCTION_MACRO __FUNCTION__
	#else
		#define LOG_FUNCTION_MACRO __PRETTY_FUNCTION__
	#endif

#endif
