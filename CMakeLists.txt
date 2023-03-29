cmake_minimum_required(VERSION 3.24)
project(2023_I)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(progra-3)

add_executable(2023_I progra-3/s1/laba_ejercicio2.cpp)

add_executable(Cf Codeforces/Watermelon.cpp)
