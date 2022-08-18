cmake_minimum_required (VERSION 3.5)

project(Log)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)

file (GLOB_RECURSE libfiles "src/**.cpp")

add_library(log OBJECT ${libfiles})

option(LOG_MAXLEVEL "The maximum logging level that gets used (Default=LOGU)" FALSE)
if (NOT LOG_MAXLEVEL)
    set(LOG_MAXLEVEL 2)
endif()
message("[LOG INFO] Log maximum level set to " ${LOG_MAXLEVEL})
target_compile_definitions(log PUBLIC LOG_MAX_LEVEL=${LOG_MAXLEVEL})

option(LOG_NOCHECK "Disable safety checks (can cause nullptrs!)" OFF)
if (LOG_NOCHECK)
    message("[LOG INFO] Building with log checks disabled, this can cause segfaults!")
    target_compile_definitions(log PRIVATE "LOG_NOCHECK")
endif()

option(LOG_NOMUTEX "Disable the logging mutex to improve performance, log messages can overlap!")
if (LOG_NOMUTEX)
    message("[LOG INFO] Building with logging mutex disabled, this can lead to overlapping messages!")
    target_compile_definitions(log PRIVATE "LOG_NOMUTEX")
endif()

option(LOG_PROFILING "Enable profiling support" OFF)
if (LOG_PROFILING)
    message("[LOG INFO] Building with profiling support, this will slow down your application!")
    target_compile_definitions(log PUBLIC "LOG_ENABLE_PROFILING")
endif()
