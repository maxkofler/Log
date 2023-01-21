#include <gtest/gtest.h>
#include <fstream>

#define FRIEND_LOG
#include "log.h"

TEST(Log, setProfileStream){
	Log::Log *hlog;

	hlog = new Log::Log();

	ASSERT_EQ(nullptr, hlog->_profile_stream) << "Stream is not initialized to nullptr";

	std::ofstream file;
	file.setstate(std::ios::badbit);

	ASSERT_FALSE(hlog->setProfileStream(&file)) << "Does not react to bad stream";

	file.open("TestingFileThisShouldNotFail.json");

	if (!file.is_open())
		FAIL() << "Failed to open test file!";

	ASSERT_TRUE(hlog->setProfileStream(&file)) << "Fails to add intact stream";
	EXPECT_EQ(&file, hlog->_profile_stream) << "Stream is not set correctly";
}
