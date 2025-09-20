cmake_minimum_required(VERSION 3.31.6)
project(Sequence)

set(CMAKE_CXX_STANDARD 20)

add_executable(sequence
        main.cpp
        Sequence.cpp
        Sequence.h
)