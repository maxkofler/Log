#ifndef __WIN32_H__
#define __WIN32_H__

	#ifdef LOG_NOCHECK

		#define FUN() Log::LogFunction currentFunction(__FUNCTION__);

		#define LOGUE(msg) hlog->log(Log::UE, __FUNCTION__, msg)
		#define LOGUW(msg) hlog->log(Log::UW, __FUNCTION__, msg)
		#define LOGU(msg) hlog->log(Log::U, __FUNCTION__, msg)
		#define LOGP(msg) hlog->log(Log::P, __FUNCTION__, msg)
		#define LOGE(msg) hlog->log(Log::E, __FUNCTION__, msg)
		#define LOGW(msg) hlog->log(Log::W, __FUNCTION__, msg)
		#define LOGI(msg) hlog->log(Log::I, __FUNCTION__, msg)
		#define LOGDE(msg) hlog->log(Log::DE, __FUNCTION__, msg)
		#define LOGDW(msg) hlog->log(Log::DW, __FUNCTION__, msg)
		#define LOGDI(msg) hlog->log(Log::DI, __FUNCTION__, msg)
		#define LOGD(msg) hlog->log(Log::D, __FUNCTION__, msg)
		#define LOGAPI(msg) hlog->log(Log::API, __FUNCTION__, msg)
		#define LOGF(msg) hlog->log(Log::F, __FUNCTION__, msg)
		#define LOGN(msg) hlog->log(Log::N, __FUNCTION__, msg)
		#define LOGIO(msg) hlog->log(Log::IO, __FUNCTION__, msg)
		#define LOGMEM(msg) hlog->log(Log::MEM, __FUNCTION__, msg)
		#define LOGFUNCALLS(msg) hlog->log(Log::FUNCALLS, __FUNCTION__, msg)

	#else

		#define FUN() Log::LogFunction currentFunction(__FUNCTION__);

		#define LOGUE(msg) Log::Log::tryLog(Log::UE, __FUNCTION__, msg)
		#define LOGUW(msg) Log::Log::tryLog(Log::UW, __FUNCTION__, msg)
		#define LOGU(msg) Log::Log::tryLog(Log::U, __FUNCTION__, msg)
		#define LOGP(msg) Log::Log::tryLog(Log::P, __FUNCTION__, msg)
		#define LOGE(msg) Log::Log::tryLog(Log::E, __FUNCTION__, msg)
		#define LOGW(msg) Log::Log::tryLog(Log::W, __FUNCTION__, msg)
		#define LOGI(msg) Log::Log::tryLog(Log::I, __FUNCTION__, msg)
		#define LOGDE(msg) Log::Log::tryLog(Log::DE, __FUNCTION__, msg)
		#define LOGDW(msg) Log::Log::tryLog(Log::DW, __FUNCTION__, msg)
		#define LOGDI(msg) Log::Log::tryLog(Log::DI, __FUNCTION__, msg)
		#define LOGD(msg) Log::Log::tryLog(Log::D, __FUNCTION__, msg)
		#define LOGAPI(msg) Log::Log::tryLog(Log::API, __PRETTY_FUNCTION__, msg)
		#define LOGF(msg) Log::Log::tryLog(Log::F, __FUNCTION__, msg)
		#define LOGN(msg) Log::Log::tryLog(Log::N, __FUNCTION__, msg)
		#define LOGIO(msg) Log::Log::tryLog(Log::IO, __FUNCTION__, msg)
		#define LOGMEM(msg) Log::Log::tryLog(Log::MEM, __FUNCTION__, msg)

		#define LOGFUNCALLS(msg) Log::Log::tryLog(Log::FUNCALLS, __FUNCTION__, msg)

	#endif

#endif
