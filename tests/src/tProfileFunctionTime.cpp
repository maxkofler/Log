#include <gtest/gtest.h>
#include <iostream>

#include "log.h"

TEST(Log, profileFunctionTime_output){
	Log::Log* hlog = new Log::Log(Log::FUNCALLS);
	hlog->setProfileStream(&std::cout);
	hlog->setFeature(Log::FEATURE_PROFILE, true);

	FUN();

	std::cout << "[TEST] A function profile should appear" << std::endl;
	struct Log::function_profile res;
	res.funName = "LogTestingFunction";
	res.start = 10;
	res.end = 10000;
	res.procID = 23256;
	res.threadID = 2804752409;
	hlog->profileFunctionTime(res);

	hlog->setFeature(Log::FEATURE_PROFILE, false);
	std::cout << "\n[TEST] No function profile should appear" << std::endl;
	hlog->profileFunctionTime(res);
}
