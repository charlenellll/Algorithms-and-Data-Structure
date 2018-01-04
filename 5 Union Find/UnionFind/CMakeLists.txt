cmake_minimum_required(VERSION 3.8)
project(UnionFind)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp UnionFind1.h UnionFindTestHelper.h UnionFind2.h UnionFind3.h UnionFind4.h UnionFind5.h)
add_executable(UnionFind ${SOURCE_FILES})