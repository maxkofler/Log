cmake_minimum_required (VERSION 3.5)

project(Log)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)

include_directories(./include)

file (GLOB_RECURSE libfiles "${PROJECT_SOURCE_DIR}/src/**.cpp")

add_library(log STATIC ${libfiles})