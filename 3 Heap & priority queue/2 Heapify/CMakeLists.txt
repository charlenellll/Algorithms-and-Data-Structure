cmake_minimum_required(VERSION 3.8)
project(Heapify)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Heap.h MergeSort.h QuickSort.h SortTestHelper.h InsertionSort.h)
add_executable(Heapify ${SOURCE_FILES})