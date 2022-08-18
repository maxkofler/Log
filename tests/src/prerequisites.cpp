#include <gtest/gtest.h>

#include "log.h"

TEST(Log, hlogUninitialized){
	delete hlog;
	hlog = nullptr;
	ASSERT_FALSE(Log::Log::check());
}

TEST(Log, hlogNew){
	hlog = new Log::Log(Log::D);

	#ifdef LOG_ENABLE_PROFILING
	hlog->setFeature(Log::FEATURE_PROFILE, true);
	hlog->setProfileStream(&std::cout);
	#endif
	
	std::cout << "Now no function call should appear" << std::endl;
	FUN();
	ASSERT_TRUE(Log::Log::check());
}
