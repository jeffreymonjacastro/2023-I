cmake_minimum_required(VERSION 3.24)
project(2023_I)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(progra-3)

add_executable(2023_I progra-3/s5_chavez/pcs1/Sobrecargas.cpp)

add_executable(pcs progra-3/s5_chavez/pcs1/lab101p2.cpp)

add_executable(Dayane progra-3/Dayane/main.cpp progra-3/Dayane/foo.h progra-3/Dayane/foo.cpp)

add_executable(clasescpc CPC/Beginners_trainee/Sesions/codes1.cpp)

add_executable(vjudge CPC/Beginners_trainee/Contest_1/D.cpp)

add_executable(Cf CPC/Codeforces/Watermelon.cpp)

add_executable(mentoria Mentoria/sesion_3/Otrapc1.cpp)
