#include <gtest/gtest.h>

#ifdef LOG_NOCHECK
	#undef LOG_NOCHECK
#endif

#include "log.h"

TEST(Log, output){
	delete hlog;
	hlog = nullptr;
	ASSERT_FALSE(LOGUE("ERROR"));
	hlog = new Log::Log(Log::A);
	Log::Log::resetWarnings();
	FUN();
	hlog->setFeature(Log::FEATURE_PRINTFUNNAMES, true);
	ASSERT_TRUE(LOGUE("OK"));
	hlog->setFeature(Log::FEATURE_PRINTFUNNAMES, false);
	ASSERT_TRUE(LOGUW("OK, NO FUNCTION NAME"));
}
