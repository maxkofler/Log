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

	ASSERT_EQ(testStr + "\n", ss.str()) << "Did not log the string to the sstream";

	l.log(Log::MEM, "TestFun", testStr);
	ASSERT_EQ(testStr + "\n", ss.str()) << "Accidentally logged wrong loglevel to sstream";

	Log::stream_config* cNew = l.getStreamConf(ss);
	ASSERT_NE(nullptr, cNew) << "Could not find associated stream!";

	cNew->loglevel = Log::MEM;

	l.log(Log::MEM, "TestFun", testStr);
	ASSERT_EQ(testStr + "\n" + testStr + "\n", ss.str()) << "Loglevel did not change";
}
