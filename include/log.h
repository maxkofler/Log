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
        E,                  //Error
        W,                  //Warning
        I,                  //Info
		P,                  //Programmer info (implementation warnings...)
		DE,					//Debug Error (for developer)
		DW,					//Debug Warning (for developer)
		DI,					//Debug Info (for developer)
		D,                  //Debug
        API,                //API calls / requests
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

	#ifdef WIN32
		#include "platforms/win32.h"
	#else
		#include "platforms/gcc.h"
	#endif

#endif
