cmake_minimum_required(VERSION 3.19.2)
project(algorithm_training C)
project(algorithm_training_2 CXX)

set(CMAKE_C_STANDARD 99)

file(GLOB src_head_base "src/main/head/base.h")
file(GLOB src_c_src_0 "src/main/clang/link_list_reversal/*.c")
file(GLOB src_c_src_1 "src/main/clang/tree/*.c")

add_executable(algorithm_training main.c
        src/main/head/export_index.h
        ${src_head_base} ${src_c_src_0}
        ${src_c_src_1}
        src/main/clang/deque/DequeDemo.c
        src/main/clang/stack/TwoStackInOneArray.c)

add_executable(algorithm_training_2 main2.cpp
        src/main/head/cpp_index.h)
