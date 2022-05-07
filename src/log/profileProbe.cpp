#ifdef LOG_ENABLE_PROFILING

#include "log.h"
#include <chrono>
#include <thread>

namespace Log{

	ProfileProbe::ProfileProbe(){
	}

	ProfileProbe::ProfileProbe(std::string name, bool autoStart){
		_result.funName = name;
		if (autoStart)
			this->start();
	}

	void ProfileProbe::start(){
		using namespace std::chrono;
		_result.start = time_point_cast<microseconds>(high_resolution_clock::now()).time_since_epoch().count();
		_result.threadID = std::hash<std::thread::id>()(std::this_thread::get_id());
	}

	void ProfileProbe::stop(){
		using namespace std::chrono;
		_result.end = time_point_cast<microseconds>(high_resolution_clock::now()).time_since_epoch().count();
	}

	struct function_profile ProfileProbe::get(){
		return _result;
	}

}



#endif