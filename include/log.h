#ifndef __LOG_H__
#define __LOG_H__

#include <map>
#include <ostream>
#include <string>
#include <deque>

#ifndef LOG_NOMUTEX
#include <mutex>
#endif


namespace Log{
	class Log;
	class Progress;
	class conf_Progress;
}

#include "progress.h"

extern Log::Log* hlog;

namespace Log{
	enum level{
		UE=0,				//User Error
		UW=1,				//User Warning
		U=2,				//User
		E=3,				//Error
		W=4,				//Warning
		I=5,				//Info
		P=6,				//Programmer info (implementation warnings...)
		DE=7,				//Debug Error (for developer)
		DW=8,				//Debug Warning (for developer)
		DI=9,				//Debug Info (for developer)
		D=10,				//Debug
		API=11,				//API calls / requests
		F=12,				//Files
		N=13,				//Networking
		IO=14,				//Input / Output (Bus)
		MEM=15,				//Memory (allocating...)
		FUNCALLS=16,		//Function calls being plot
		A=17				//Everything
	};

	enum feature{
		FEATURE_PROFILE				//If Log should produce a profile trace, this impacts performance
	};

	struct function_profile{
		std::string funName;
		long long start, end;
		size_t threadID;
		size_t procID;
	};

	struct stream_config{
		level	loglevel;
		bool	print_function_names = false;
		bool	enable_colors = true;
		bool	enable_progress = false;
	};

	class Log{

	public:
		Log();
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
		 * @brief	Resets all the warnings that block the Log module from checking some things again due to performance reasons
		 */
		static void						resetWarnings();

		/**
		 * @brief	Adds a output stream to this Log instance
		 * @param	stream				The stream to output to
		 * @param	stream_config		The stream configuration to use for this stream
		 * @return	bool	False if the stream has already been added
		 */
		bool							addStream(std::ostream& stream, stream_config conf);

		/**
		 * @brief	Returns a pointer to the stream config
		 * @param	stream				The stream to get the config from
		 */
		stream_config*					getStreamConf(std::ostream& stream);

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

		/**
		 * @brief	Updates the terminal width
		 * @param	width				The new width to use
		 */
		void							setTerminalWidth(uint32_t width);

		/**
		 * @brief	Returns the terminal width last set by setTerminalWidth()
		 */
		uint32_t						getTerminalWidth();

		/**
		 * @brief	Returns a new progress using the supplied config
		 * @param	config				The config to use
		 */
		std::shared_ptr<Progress>		createProgress(const conf_Progress& config);

		//The Progress class is a friend
		friend class Progress;
	#ifndef FRIEND_LOG
	private:
	#endif

		#ifndef LOG_NOMUTEX
		std::mutex						_m_logging;
		#endif

		bool							_enable_profiling;
		size_t							_profiles_count;
		std::ostream*					_profile_stream;

		/**
		 * @brief	A map containing all the output streams and their levels
		 */
		std::map<std::ostream*, stream_config>	_streams;

		///
		///		Progress management
		///

		/// @brief	A list of pointer to progresses managed by this Log instance
		std::deque<Progress*>			_progresses;

		/// @brief	Terminal width, needed for progress
		uint32_t						_terminal_width = 0;

		/**
		 * @brief	A callback for a Progress object, this removes this progress from the _progresses list
		 * @param	progress			A pointer to the progress to remove
		 */
		void							removeProgress(Progress* progress);

		/**
		 * @brief	A callback for a Progress object to signal it has been updated
		 * @param	progress			The progress that signals the update
		 */
		void							progressUpdated(Progress* progress);
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

		#ifdef LOG_ENABLE_PROFILING
		ProfileProbe					_profileProbe;
		#endif
	};
};

	#include "levels.h"
	#include "fun.h"

#endif
