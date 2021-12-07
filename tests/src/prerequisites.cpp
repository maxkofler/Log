#include <gtest/gtest.h>

#include "log.h"

Log::Log* hlog = nullptr;

TEST(Log, hlogUninitialized){
	delete hlog;
	hlog = nullptr;
	ASSERT_FALSE(Log::Log::check());
}

TEST(Log, hlogNew){
	hlog = new Log::Log(Log::D);
	std::cout << "Now no function call should appear" << std::endl;
	FUN();
	ASSERT_TRUE(Log::Log::check());
}
