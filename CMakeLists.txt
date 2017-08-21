cmake_minimum_required (VERSION 2.6)
project (fsm)

include_directories ("${PROJECT_SOURCE_DIR}/inc")
add_subdirectory(${PROJECT_SOURCE_DIR}/inc/googletest)

add_executable(fsm main.cpp)

add_executable(mytest test.cpp)
target_link_libraries(mytest gtest_main)
add_test(NAME example_test COMMAND mytest)
