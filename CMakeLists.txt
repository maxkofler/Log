cmake_minimum_required (VERSION 3.5)

project(Log)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(LOG_PROFILING "Enable profiling support" OFF)
if (LOG_PROFILING)
    message("INFO Building with profiling support, this will slow down your application!")
    add_compile_definitions("LOG_ENABLE_PROFILING")
endif()

include_directories(include)

file (GLOB_RECURSE libfiles "src/**.cpp")

add_library(log OBJECT ${libfiles})