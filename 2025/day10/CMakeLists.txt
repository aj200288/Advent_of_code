cmake_minimum_required(VERSION 3.10)
project(cpp_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add debug flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Set default build type to Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Main executable
add_executable(main main.cpp functions.cpp)
target_link_libraries(main z3) # only for day10

# Testing - stays in build folder
enable_testing()
find_package(GTest REQUIRED)

add_executable(tests tests/test_main.cpp functions.cpp)
target_link_libraries(tests GTest::gtest GTest::gtest_main pthread z3)

add_test(NAME unit_tests COMMAND tests)
