#include <gtest/gtest.h>

#include "log.h"

TEST(Log, output){
    delete hlog;
    hlog = nullptr;
    ASSERT_FALSE(LOGUE("ERROR"));
    hlog = new Log::Log(Log::A);
    FUN();
    ASSERT_TRUE(LOGUE("OK"));
}