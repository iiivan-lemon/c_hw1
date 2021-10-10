cmake_minimum_required(VERSION 3.20)
project(c_hw1 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

add_compile_options("--coverage")
add_link_options("--coverage")

add_library(utils STATIC project/from_one_to_three.c)
target_include_directories(utils PUBLIC project)

add_executable(c_hw1 project/main.c)
target_link_libraries(c_hw1 utils)

find_package(GTest REQUIRED)
set(SOURCES tests/run_tests.cpp tests/test.cpp )
add_executable(runTests ${SOURCES})
target_link_libraries(runTests GTest::gtest utils)

