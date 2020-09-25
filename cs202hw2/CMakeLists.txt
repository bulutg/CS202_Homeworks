cmake_minimum_required(VERSION 3.16)
project(cs202hw2)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs202hw2 hw2.cpp NgramTree.cpp NgramTree.h TreeNode.cpp TreeNode.h)