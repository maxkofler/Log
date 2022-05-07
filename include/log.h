#ifndef __LOG_H__
#define __LOG_H__

#include <ostream>
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
		FEATURE_PRINTFUNNAMES,		//If Log should print the function name of the log message
		FEATURE_PROFILE				//If Log should produce a profile trace, this impacts performance
	};

	struct function_profile{
		std::string funName;
		long long start, end;
		size_t threadID;
		size_t procID;
	};

	class Log{

	public:
		Log(level loglevel);
		~Log();

		/**
		 * @brief	Sets the output stream for the profiling output
		 * @param	stream				The stream
		 */
		bool							setProfileStream(std::ostream* stream);

		/**
		 * @brief						Returns if the global log variable is present and initialized
		 */
		static bool						check();

		/**
		 * @brief						Tries to log the provided contents (USED ONLY BY MACRO!!!)
		 */
		static bool						tryLog(level loglevel, std::string function, std::string message);

		/**
		 * @brief						En/Disables the provided feature
		 */
		bool							setFeature(feature feature, bool state);

		bool							log(level loglevel, std::string function, std::string message);
		bool							log(level loglevel, std::string function, const char* message);

		/**
		 * @brief	Writes an entry to the profiling file
		 * @param	res					The function profile result
		 */
		bool							profileFunctionTime(struct function_profile res);

		/**
		 * @brief	Writes the necessary header to the profiling stream
		 */
		void							writeProfileHeader();

		/**
		 * @brief	Writes the necessary footer to the profiling stream
		 */
		void							writeProfileFooter();

		level							getLevel();
		void							setLevel(level loglevel);

	#ifndef FRIEND_LOG
	private:
	#endif

		level							_loglevel;
		bool							_print_function_names;
		std::mutex						_m_logging;

		bool							_enable_profiling;
		size_t							_profiles_count;
		std::ostream*					_profile_stream;
	};

	class ProfileProbe{
	public:
		ProfileProbe();
		ProfileProbe(std::string name, bool start = false);

		void							setName(std::string name);

		void 							start();
		void							stop();

		struct function_profile			get();

	private:
		struct function_profile		_result;
	};

	class LogFunction{
	public:
		LogFunction(std::string name);
		~LogFunction();
	private:

		std::string						_name;
		ProfileProbe					_profileProbe;
	};
};

	#ifdef WIN32
		#include "platforms/win32.h"
	#else
		#include "platforms/gcc.h"
	#endif

#endif
