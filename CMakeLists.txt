cmake_minimum_required(VERSION 3.24)
project(2023_I)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(progra-3)

add_executable(2023_I progra-3/s3_chavez/Lab_b/ejercicio003.cpp)

add_executable(clasescpc CPC/Beginners_trainee/Sesions/codes1.cpp)

add_executable(vjudge CPC/Beginners_trainee/Contest_1/F.cpp)

add_executable(Cf CPC/Codeforces/Watermelon.cpp)

add_executable(mentoria Mentoria/sesion_2/funciones.cpp Mentoria/sesion_2/header.h)
