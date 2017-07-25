cmake_minimum_required(VERSION 3.8)
project(MergeSortFromBottomUp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MergeSort.h SortTestHelper.h InsertionSort.h)
add_executable(MergeSortFromBottomUp ${SOURCE_FILES})