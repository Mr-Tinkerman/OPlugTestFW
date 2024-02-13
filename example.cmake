cmake_minimum_required(VERSION 3.10)
project(OPlugTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests)

add_oplugtest(RunAllTests EXAMPLE.cpp)
