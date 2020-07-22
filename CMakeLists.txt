cmake_minimum_required(VERSION 3.10)
project(AlgoPlayground)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgoPlayground divide-conquer/week4/MinCut.cc divide-conquer/week4/WeightedUF.cpp divide-conquer/week4/WeightedUF.h divide-conquer/week4/Graph.cpp divide-conquer/week4/Graph.h)