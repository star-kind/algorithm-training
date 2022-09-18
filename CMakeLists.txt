cmake_minimum_required(VERSION 3.19.2)
project(algorithm_training C)
project(algorithm_training_cpp CXX)

set(CMAKE_C_STANDARD 99)

file(GLOB src_head_base "src/main/head/base.h")
file(GLOB src_c_src_0 "src/main/clang/link_list_reversal/*.c")

add_executable(algorithm_training main.c
        src/main/head/export_index.h
        ${src_head_base} ${src_c_src_0}
        src/main/clang/deque/DequeDemo.c
        src/main/clang/stack/TwoStackInOneArray.c)

add_executable(algorithm_training_cpp main_cxx.cpp
        src/main/clang/binary_tree/TreeSample.cpp
        src/main/head/clang_plus_x.h
        src/main/clang/binary_tree/TreeCase.cpp
        src/main/clang/binary_tree/TreeDemo.cpp
        src/main/clang/binary_tree/BinTreeDemo.cpp
        )