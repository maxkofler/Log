#ifndef __LOG_H__
#define __LOG_H__

#include <string>
#include <mutex>

namespace Log{
    class Log;
}

extern Log::Log* hlog;

namespace Log{
    enum level{
        UE,                 //User Error
        UW,                 //User Warning
        U,                  //User
        P,                  //Programmer
        E,                  //Error
        W,                  //Warning
        I,                  //Info
        D,                  //Debug
        F,                  //Files
        N,                  //Networking
        IO,                 //Input / Output (Bus)
        MEM,                //Memory (allocating...)
        FUNCALLS,           //Function calls being plot
        A                   //Everything
    };

    enum feature{
        FEATURE_PRINTFUNNAMES
    };

    class Log{

    public:
        Log(level loglevel);

        /**
         * @brief                           Returns if the global log variable is present and initialized
         */
        static bool                         check();

        /**
         * @brief                           Tries to log the provided contents (USED ONLY BY MACRO!!!)
         */
        static bool                         tryLog(level loglevel, std::string function, std::string message);

        /**
         * @brief                           En/Disables the provided feature
         */
        bool                                setFeature(feature feature, bool state);

        bool                                log(level loglevel, std::string function, std::string message);
        bool                                log(level loglevel, std::string function, const char* message);

        level                               getLevel();
        void                                setLevel(level loglevel);
    
    private:
        level                               _loglevel;
        bool                                _print_function_names;
        std::mutex                          _m_logging;
    };

    class LogFunction{
    public:
        LogFunction(std::string name);
        ~LogFunction();
    private:
        std::string                         _name;
    };
};

#ifdef LOG_NOCHECK
    #ifdef WIN32
        #define FUN() Log::LogFunction currentFunction(__FUNCTION__);

        #define LOGUE(msg) hlog->log(Log::UE, __FUNCTION__, msg)
        #define LOGUW(msg) hlog->log(Log::UW, __FUNCTION__, msg)
        #define LOGU(msg) hlog->log(Log::U, __FUNCTION__, msg)
        #define LOGP(msg) hlog->log(Log::P, __FUNCTION__, msg)
        #define LOGE(msg) hlog->log(Log::E, __FUNCTION__, msg)
        #define LOGW(msg) hlog->log(Log::W, __FUNCTION__, msg)
        #define LOGI(msg) hlog->log(Log::I, __FUNCTION__, msg)
        #define LOGD(msg) hlog->log(Log::D, __FUNCTION__, msg)
        #define LOGF(msg) hlog->log(Log::F, __FUNCTION__, msg)
        #define LOGN(msg) hlog->log(Log::N, __FUNCTION__, msg)
        #define LOGIO(msg) hlog->log(Log::IO, __FUNCTION__, msg)
        #define LOGMEM(msg) hlog->log(Log::MEM, __FUNCTION__, msg)
    #else
        #define FUN() Log::LogFunction currentFunction(__PRETTY_FUNCTION__);

        #define LOGUE(msg) hlog->log(Log::UE, __PRETTY_FUNCTION__, msg)
        #define LOGUW(msg) hlog->log(Log::UW, __PRETTY_FUNCTION__, msg)
        #define LOGU(msg) hlog->log(Log::U, __PRETTY_FUNCTION__, msg)
        #define LOGP(msg) hlog->log(Log::P, __PRETTY_FUNCTION__, msg)
        #define LOGE(msg) hlog->log(Log::E, __PRETTY_FUNCTION__, msg)
        #define LOGW(msg) hlog->log(Log::W, __PRETTY_FUNCTION__, msg)
        #define LOGI(msg) hlog->log(Log::I, __PRETTY_FUNCTION__, msg)
        #define LOGD(msg) hlog->log(Log::D, __PRETTY_FUNCTION__, msg)
        #define LOGF(msg) hlog->log(Log::F, __PRETTY_FUNCTION__, msg)
        #define LOGN(msg) hlog->log(Log::N, __PRETTY_FUNCTION__, msg)
        #define LOGIO(msg) hlog->log(Log::IO, __PRETTY_FUNCTION__, msg)
        #define LOGMEM(msg) hlog->log(Log::MEM, __PRETTY_FUNCTION__, msg)
    #endif

#else

    #ifdef WIN32
        #define FUN() Log::LogFunction currentFunction(__FUNCTION__);

        #define LOGUE(msg) Log::Log::tryLog(Log::UE, __FUNCTION__, msg)
        #define LOGUW(msg) Log::Log::tryLog(Log::UW, __FUNCTION__, msg)
        #define LOGU(msg) Log::Log::tryLog(Log::U, __FUNCTION__, msg)
        #define LOGP(msg) Log::Log::tryLog(Log::P, __FUNCTION__, msg)
        #define LOGE(msg) Log::Log::tryLog(Log::E, __FUNCTION__, msg)
        #define LOGW(msg) Log::Log::tryLog(Log::W, __FUNCTION__, msg)
        #define LOGI(msg) Log::Log::tryLog(Log::I, __FUNCTION__, msg)
        #define LOGD(msg) Log::Log::tryLog(Log::D, __FUNCTION__, msg)
        #define LOGF(msg) Log::Log::tryLog(Log::F, __FUNCTION__, msg)
        #define LOGN(msg) Log::Log::tryLog(Log::N, __FUNCTION__, msg)
        #define LOGIO(msg) Log::Log::tryLog(Log::IO, __FUNCTION__, msg)
        #define LOGMEM(msg) Log::Log::tryLog(Log::MEM, __FUNCTION__, msg)
    #else
        #define FUN() Log::LogFunction currentFunction(__PRETTY_FUNCTION__);

        #define LOGUE(msg) Log::Log::tryLog(Log::UE, __PRETTY_FUNCTION__, msg)
        #define LOGUW(msg) Log::Log::tryLog(Log::UW, __PRETTY_FUNCTION__, msg)
        #define LOGU(msg) Log::Log::tryLog(Log::U, __PRETTY_FUNCTION__, msg)
        #define LOGP(msg) Log::Log::tryLog(Log::P, __PRETTY_FUNCTION__, msg)
        #define LOGE(msg) Log::Log::tryLog(Log::E, __PRETTY_FUNCTION__, msg)
        #define LOGW(msg) Log::Log::tryLog(Log::W, __PRETTY_FUNCTION__, msg)
        #define LOGI(msg) Log::Log::tryLog(Log::I, __PRETTY_FUNCTION__, msg)
        #define LOGD(msg) Log::Log::tryLog(Log::D, __PRETTY_FUNCTION__, msg)
        #define LOGF(msg) Log::Log::tryLog(Log::F, __PRETTY_FUNCTION__, msg)
        #define LOGN(msg) Log::Log::tryLog(Log::N, __PRETTY_FUNCTION__, msg)
        #define LOGIO(msg) Log::Log::tryLog(Log::IO, __PRETTY_FUNCTION__, msg)
        #define LOGMEM(msg) Log::Log::tryLog(Log::MEM, __PRETTY_FUNCTION__, msg)
    #endif

#endif

#endif