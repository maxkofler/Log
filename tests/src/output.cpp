#include <gtest/gtest.h>

#ifdef LOG_NOCHECK
	#undef LOG_NOCHECK
#endif

#include "log.h"

//TODO: Remake this test
TEST(Log, output){
	delete hlog;
	hlog = nullptr;
	ASSERT_FALSE(LOGUE("ERROR"));
	hlog = new Log::Log();
	Log::Log::resetWarnings();
	FUN();
	ASSERT_TRUE(LOGUE("OK"));
	ASSERT_TRUE(LOGUW("OK, NO FUNCTION NAME"));
}
