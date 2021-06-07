cmake_minimum_required (VERSION 3.5)

include_directories(./include)

file (GLOB_RECURSE libfiles "./logsrc/*cpp")
add_library(log STATIC ${libfiles})