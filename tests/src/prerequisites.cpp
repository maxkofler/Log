#include <gtest/gtest.h>

#include "log.h"

Log::Log* hlog = nullptr;

TEST(Log, hlogUninitialized){
    EXPECT_FALSE(Log::Log::check());
}

TEST(Log, hlogNew){
    hlog = new Log::Log(Log::D);
    EXPECT_TRUE(Log::Log::check());
}