
cmake_minimum_required(VERSION 3.5)
project (LogTests)

include_directories(../include)

file(GLOB_RECURSE Sources "src/**.cpp")

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} PUBLIC
    gtest_main
    log
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
