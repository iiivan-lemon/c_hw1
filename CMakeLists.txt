cmake_minimum_required(VERSION 3.20)
project(hw_2 C CXX)

option(parallel "build" OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread ")
set(CMAKE_C_CLANG_TIDY clang-tidy; -checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus*)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wpedantic -Werror --coverage ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -Wpedantic -Werror  --coverage ")


if(address)
    message("address")
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
elseif(memory)
    message("memory")
    add_compile_options(-fsanitize=leak)   # -fsanitize=memory don't work, change to leak
    add_link_options(-fsanitize=leak)
elseif(undefined)
    message("undefined")
    add_compile_options(-fsanitize=undefined)
    add_link_options(-fsanitize=undefined)
elseif(thread)
    message("thread")
    add_compile_options(-fsanitize=thread)
    add_link_options(-fsanitize=thread)
endif()



add_library(input_data STATIC project/input_data.c)
target_include_directories(input_data PUBLIC project)


add_library(consistent STATIC project/prog.c)
target_include_directories(consistent PUBLIC project)
target_link_libraries(consistent PUBLIC input_data)
target_link_libraries(consistent PRIVATE m)

add_library(parallel SHARED project/parallel_prog.c)
target_include_directories(parallel PUBLIC project)
target_link_libraries(parallel PUBLIC input_data)
target_link_libraries(parallel PRIVATE m)

add_executable(hw_2 project/main.c)

find_package(GTest REQUIRED)
add_executable(tests tests/test.cpp tests/input_test.cpp)

if (parallel)
    message("parallel")
    target_link_libraries(hw_2 parallel gcov)
    target_link_libraries(tests GTest::gtest parallel input_data gcov)
else ()
    message("consistent")
    target_link_libraries(hw_2 consistent gcov)
    target_link_libraries(tests GTest::gtest consistent input_data gcov)
endif (parallel)

add_executable(consistent_test tests/consistent_stress_test.cpp)
target_link_libraries(consistent_test GTest::gtest consistent input_data gcov)

add_executable(parallel_test tests/parallel_stress_test.cpp)
target_link_libraries(parallel_test GTest::gtest parallel input_data gcov)

add_executable(comparison tests/comparison.cpp)
target_link_libraries(comparison GTest::gtest gcov)