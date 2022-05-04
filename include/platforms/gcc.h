#ifndef __GCC_H__
#define __GCC_H__

	#ifdef LOG_NOCHECK

		#define FUN() Log::LogFunction currentFunction(__PRETTY_FUNCTION__);

		#define LOGUE(msg) hlog->log(Log::UE, __PRETTY_FUNCTION__, msg)
		#define LOGUW(msg) hlog->log(Log::UW, __PRETTY_FUNCTION__, msg)
		#define LOGU(msg) hlog->log(Log::U, __PRETTY_FUNCTION__, msg)
		#define LOGP(msg) hlog->log(Log::P, __PRETTY_FUNCTION__, msg)
		#define LOGE(msg) hlog->log(Log::E, __PRETTY_FUNCTION__, msg)
		#define LOGW(msg) hlog->log(Log::W, __PRETTY_FUNCTION__, msg)
		#define LOGI(msg) hlog->log(Log::I, __PRETTY_FUNCTION__, msg)
		#define LOGDE(msg) hlog->log(Log::DE, __PRETTY_FUNCTION__, msg)
		#define LOGDW(msg) hlog->log(Log::DW, __PRETTY_FUNCTION__, msg)
		#define LOGDI(msg) hlog->log(Log::DI, __PRETTY_FUNCTION__, msg)
		#define LOGD(msg) hlog->log(Log::D, __PRETTY_FUNCTION__, msg)
		#define LOGAPI(msg) hlog->log(Log::API, __PRETTY_FUNCTION__, msg)
		#define LOGF(msg) hlog->log(Log::F, __PRETTY_FUNCTION__, msg)
		#define LOGN(msg) hlog->log(Log::N, __PRETTY_FUNCTION__, msg)
		#define LOGIO(msg) hlog->log(Log::IO, __PRETTY_FUNCTION__, msg)
		#define LOGMEM(msg) hlog->log(Log::MEM, __PRETTY_FUNCTION__, msg)
		#define LOGFUNCALLS(msg) hlog->log(Log::FUNCALLS, __PRETTY_FUNCTION__, msg)

	#else

		#define FUN() Log::LogFunction currentFunction(__PRETTY_FUNCTION__);

		#define LOGUE(msg) Log::Log::tryLog(Log::UE, __PRETTY_FUNCTION__, msg)
		#define LOGUW(msg) Log::Log::tryLog(Log::UW, __PRETTY_FUNCTION__, msg)
		#define LOGU(msg) Log::Log::tryLog(Log::U, __PRETTY_FUNCTION__, msg)
		#define LOGP(msg) Log::Log::tryLog(Log::P, __PRETTY_FUNCTION__, msg)
		#define LOGE(msg) Log::Log::tryLog(Log::E, __PRETTY_FUNCTION__, msg)
		#define LOGW(msg) Log::Log::tryLog(Log::W, __PRETTY_FUNCTION__, msg)
		#define LOGI(msg) Log::Log::tryLog(Log::I, __PRETTY_FUNCTION__, msg)
		#define LOGDE(msg) Log::Log::tryLog(Log::DE, __PRETTY_FUNCTION__, msg)
		#define LOGDW(msg) Log::Log::tryLog(Log::DW, __PRETTY_FUNCTION__, msg)
		#define LOGDI(msg) Log::Log::tryLog(Log::DI, __PRETTY_FUNCTION__, msg)
		#define LOGD(msg) Log::Log::tryLog(Log::D, __PRETTY_FUNCTION__, msg)
		#define LOGAPI(msg) Log::Log::tryLog(Log::API, __PRETTY_FUNCTION__, msg)
		#define LOGF(msg) Log::Log::tryLog(Log::F, __PRETTY_FUNCTION__, msg)
		#define LOGN(msg) Log::Log::tryLog(Log::N, __PRETTY_FUNCTION__, msg)
		#define LOGIO(msg) Log::Log::tryLog(Log::IO, __PRETTY_FUNCTION__, msg)
		#define LOGMEM(msg) Log::Log::tryLog(Log::MEM, __PRETTY_FUNCTION__, msg)
		#define LOGFUNCALLS(msg) Log::Log::tryLog(Log::FUNCALLS, __PRETTY_FUNCTION__, msg)

	#endif

#endif
