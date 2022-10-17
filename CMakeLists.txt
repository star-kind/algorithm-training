cmake_minimum_required(VERSION 3.19.2)
project(algorithm_training C)
project(algorithm_training_enhance CXX)

set(CMAKE_C_STANDARD 99)

file(GLOB src_head_base "src/main/head/base.h")
file(GLOB src_c_src_0 "src/main/clang/link_list_reversal/*.c")

add_executable(algorithm_training main.c
        src/main/head/export_index.h
        ${src_head_base}
        ${src_c_src_0}
        src/main/clang/deque/DequeDemo.c
        src/main/clang/stack/TwoStackInOneArray.c
        src/main/clang/BinaryTree/LevelOrderTree.c
        src/main/clang/BinaryTree/BinaryTreeLevelOrder.c)

add_executable(algorithm_training_enhance main_enhance.cpp
        src/main/head/clang_enhance.h
        src/main/clang/binary_tree_improve/ArrBuildsTrees.cpp
        src/main/clang/binary_tree_improve/EntirelyBinTree.cpp
        src/main/clang/heaps/HeapSortsDemo.cpp
        src/main/clang/heaps/HeapSortDemo1.cpp src/main/clang/heaps/HeapSortSample.cpp)