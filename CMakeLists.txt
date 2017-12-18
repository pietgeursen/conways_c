cmake_minimum_required (VERSION 2.6)
project (conways-c)

enable_testing()

include_directories ("${PROJECT_SOURCE_DIR}/inc")

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

############################################################### 
# Ignore above here
###############################################################

# or Release if you're trying to make everything go super fast when all the tests are passing. (Will break debugging)
set(CMAKE_BUILD_TYPE Release)

# hello world
add_executable(hello_world hello_world.c)

# Pointers exercise
add_executable(pointers pointers.c)

# Conways exercise

# if you want to use different sized boards, change this. The `BOARD_SIZE` variable is available in all the code.
add_definitions(-DBOARD_SIZE=120)

# Uncomment each group below as you progress through the challenge
add_library(is_over_populated is_over_populated.c)
add_executable(is_over_populated_test is_over_populated_test.cpp)
target_link_libraries(is_over_populated_test is_over_populated gtest_main)

add_library(is_under_populated is_under_populated.c)
add_executable(is_under_populated_test is_under_populated_test.cpp)
target_link_libraries(is_under_populated_test is_under_populated gtest_main)

add_library(is_ressurectable is_ressurectable.c)
add_executable(is_ressurectable_test is_ressurectable_test.cpp)
target_link_libraries(is_ressurectable_test is_ressurectable gtest_main)

add_library(is_index_out_of_bounds is_index_out_of_bounds.c)
add_executable(is_index_out_of_bounds_test is_index_out_of_bounds_test.cpp)
target_link_libraries(is_index_out_of_bounds_test is_index_out_of_bounds gtest_main)

add_library(count_alive_neighbours count_alive_neighbours.c)
add_executable(count_alive_neighbours_test count_alive_neighbours_test.cpp)
add_executable(asm_count_alive_neighbours_test asm_count_alive_neighbours_test.cpp)
target_link_libraries(count_alive_neighbours_test count_alive_neighbours is_index_out_of_bounds gtest_main)
target_link_libraries(asm_count_alive_neighbours_test count_alive_neighbours is_index_out_of_bounds gtest_main)

add_library(next_cell_state next_cell_state.c)
add_executable(next_cell_state_test next_cell_state_test.cpp)
target_link_libraries(next_cell_state_test next_cell_state is_over_populated is_under_populated is_ressurectable gtest_main)

add_library(calculate_next_board calculate_next_board.c)
add_executable(calculate_next_board_test calculate_next_board_test.cpp)
target_link_libraries(calculate_next_board_test calculate_next_board count_alive_neighbours is_index_out_of_bounds next_cell_state is_over_populated is_under_populated is_ressurectable gtest_main)

add_executable(conways conways.c)
target_link_libraries(conways calculate_next_board count_alive_neighbours is_index_out_of_bounds next_cell_state is_over_populated is_under_populated is_ressurectable gtest_main)
# Tests that are run by cmake. Run them with `make test` or `cmake` in the build dir.
add_test(NAME is_over_populated COMMAND is_over_populated_test)
add_test(NAME is_under_populated COMMAND is_under_populated_test)
add_test(NAME is_ressurectable COMMAND is_ressurectable_test)
add_test(NAME is_index_out_of_bounds COMMAND is_index_out_of_bounds_test)
add_test(NAME next_cell_state COMMAND next_cell_state_test)
add_test(NAME count_alive_neighbours COMMAND count_alive_neighbours_test)
add_test(NAME asm_count_alive_neighbours COMMAND asm_count_alive_neighbours_test)
add_test(NAME calculate_next_board COMMAND calculate_next_board_test)
