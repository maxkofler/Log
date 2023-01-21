cmake_minimum_required (VERSION 3.5)

project(Log)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)

option(LOG_TESTS "If the log tests should be built" OFF)
option(LOG_MAXLEVEL "The maximum logging level that gets used (Default=LOGU)" FALSE)
option(LOG_NOCHECK "Disable safety checks (can cause nullptrs!)" OFF)
option(LOG_NOMUTEX "Disable the logging mutex to improve performance, log messages can overlap!")
option(LOG_NOCOLOR "Disable the logging of errors and warnings in color")
option(LOG_PROFILING "Enable profiling support" OFF)

if (LOG_TESTS)
    message("[LOG INFO] Enabled Log tests")
    enable_testing()
    set(LOG_PROFILING CACHE BOOL ON "Enable Log profiling support for testing")
    add_subdirectory(googletest)
    add_subdirectory(tests)
endif()

file (GLOB_RECURSE libfiles "src/**.cpp")

add_library(log OBJECT ${libfiles})

if (NOT LOG_MAXLEVEL)
    set(LOG_MAXLEVEL 2)
endif()
message("[LOG INFO] Log maximum level set to " ${LOG_MAXLEVEL})
target_compile_definitions(log PUBLIC LOG_MAX_LEVEL=${LOG_MAXLEVEL})

if (LOG_NOCHECK)
    message("[LOG INFO] Building with log checks disabled, this can cause segfaults!")
    target_compile_definitions(log PUBLIC "LOG_NOCHECK")
endif()

if (LOG_NOMUTEX)
    message("[LOG INFO] Building with logging mutex disabled, this can lead to overlapping messages!")
    target_compile_definitions(log PUBLIC "LOG_NOMUTEX")
endif()

if (LOG_NOCOLOR)
    message("[LOG INFO] Disabled color support")
    target_compile_definitions(log PUBLIC "LOG_NOCOLOR")
endif()

if (LOG_PROFILING)
    message("[LOG INFO] Building with profiling support, this will slow down your application!")
    target_compile_definitions(log PUBLIC "LOG_ENABLE_PROFILING")
endif()
