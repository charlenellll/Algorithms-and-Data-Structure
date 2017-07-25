cmake_minimum_required(VERSION 3.8)
project(MergeSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortTestHelper.h InsertionSort.h)
add_executable(MergeSort ${SOURCE_FILES})