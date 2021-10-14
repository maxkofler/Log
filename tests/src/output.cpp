#include <gtest/gtest.h>

#include "log.h"

TEST(Log, output){
    delete hlog;
    hlog = nullptr;
    ASSERT_FALSE(LOGUE("ERROR"));
    hlog = new Log::Log(Log::A);
    FUN();
    hlog->setFeature(Log::FEATURE_PRINTFUNNAMES, true);
    ASSERT_TRUE(LOGUE("OK"));
    hlog->setFeature(Log::FEATURE_PRINTFUNNAMES, false);
    ASSERT_TRUE(LOGUE("OK, NO FUNCTION NAME"));
}