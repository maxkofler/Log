cmake_minimum_required (VERSION 3.5)

project(Log)

include_directories(include)

file (GLOB_RECURSE libfiles "src/**.cpp")

add_library(log STATIC ${libfiles})