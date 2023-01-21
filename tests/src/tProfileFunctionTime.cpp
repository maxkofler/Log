#include <gtest/gtest.h>
#include <iostream>

#include "log.h"

//TODO: Refactor these tests
TEST(Log, profileFunctionTime_output){
	Log::Log* hlog = new Log::Log();
	hlog->setProfileStream(&std::cout);
	hlog->setFeature(Log::FEATURE_PROFILE, true);

	FUN();

	std::cout << "[TEST] A function profile should appear" << std::endl;
	Log::ProfileProbe probe1("A test function");
	Log::ProfileProbe probe2("A secondf sdoflkg", true);
	probe1.start();
	sleep(1);
	probe1.stop();
	probe2.stop();
	hlog->profileFunctionTime(probe1.get());
	hlog->profileFunctionTime(probe2.get());

	hlog->setFeature(Log::FEATURE_PROFILE, false);
	std::cout << "\n[TEST] No function profile should appear" << std::endl;
	hlog->profileFunctionTime(probe1.get());
}

TEST(Log, profileFunctionTime_scope){
	Log::Log* hlog = new Log::Log();
	hlog->setProfileStream(&std::cout);
	hlog->setFeature(Log::FEATURE_PROFILE, true);

	{
		FUN();
		sleep(1);
	}
}
