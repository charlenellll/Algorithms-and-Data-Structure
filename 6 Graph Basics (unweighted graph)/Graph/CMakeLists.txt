cmake_minimum_required(VERSION 3.8)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Component.h Path.h ShortestPath.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Graph ${SOURCE_FILES})