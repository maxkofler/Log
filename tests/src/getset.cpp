#include <gtest/gtest.h>

#include "log.h"

TEST(Log, gsLoglevel){
	Log::Log log(Log::I);
	ASSERT_EQ(Log::I, log.getLevel());
	log.setLevel(Log::D);
	EXPECT_EQ(Log::D, log.getLevel());
}
