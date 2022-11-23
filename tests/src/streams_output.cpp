/**
 * @file		tests/streams_output.cpp
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		The test for output to streams
 * @copyright	Copyright (c) 2022
 */

#include <gtest/gtest.h>

#include <sstream>

#include "log.h"

TEST(Log, Streams_Output){
	Log::Log l;

	std::stringstream ss;

	Log::stream_config c;
	c.loglevel = Log::D;
	c.print_function_names = false;

	l.addStream(ss, c);

	std::string testStr = "TestString";

	l.log(Log::D, "TestFun", testStr);

	ASSERT_EQ(testStr + "\n", ss.str());

	l.log(Log::MEM, "TestFun", testStr);
	ASSERT_EQ(testStr + "\n", ss.str());
}
