cmake_minimum_required (VERSION 2.6)
project (myExecutable)
enable_testing()

include_directories ("${PROJECT_SOURCE_DIR}/inc")

add_executable(myExecutable main.cpp)

# Download and unpack googletest at configure time
set(BUILD_GTEST ON)
set(BUILD_GMOCK OFF)
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Pointers exercise
add_executable(pointers pointers.cpp)

# Conways exercise
add_library(is_over_populated is_over_populated.cpp)
add_executable(is_over_populated_test is_over_populated_test.cpp)
target_link_libraries(is_over_populated_test is_over_populated gtest_main)

# Uncomment below as you progress through the challenge
add_library(is_under_populated is_under_populated.cpp)
add_executable(is_under_populated_test is_under_populated_test.cpp)
target_link_libraries(is_under_populated_test is_under_populated gtest_main)

add_library(is_ressurectable is_ressurectable.cpp)
add_executable(is_ressurectable_test is_ressurectable_test.cpp)
target_link_libraries(is_ressurectable_test is_ressurectable gtest_main)

add_test(NAME is_over_populated COMMAND is_over_populated_test)
add_test(NAME is_under_populated COMMAND is_under_populated_test)
add_test(NAME is_ressurectable COMMAND is_ressurectable_test)
