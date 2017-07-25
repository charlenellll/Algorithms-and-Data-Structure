cmake_minimum_required(VERSION 3.8)
project(ShellSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortTestHelper.h InsertionSort.h SelectionSort.h BubbleSort.h)
add_executable(ShellSort ${SOURCE_FILES})