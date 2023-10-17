cmake_minimum_required(VERSION 3.10)
project(lw3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${CMAKE_PROJECT_NAME}_lib figure.cpp)
target_link_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC figure.hpp)

add_executable(${CMAKE_PROJECT_NAME}_test test.cpp)

target_include_directories(${CMAKE_PROJECT_NAME}_test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME}_test ${CMAKE_PROJECT_NAME}_lib gtest gtest_main)

add_test(basic test_lw3)