cmake_minimum_required (VERSION 3.5)

project(Log)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)

file (GLOB_RECURSE libfiles "src/**.cpp")

add_library(log OBJECT ${libfiles})

option(LOG_PROFILING "Enable profiling support" OFF)
if (LOG_PROFILING)
    message("INFO Building with profiling support, this will slow down your application!")
    target_compile_definitions(log PUBLIC "LOG_ENABLE_PROFILING")
endif()
