cmake_minimum_required(VERSION 3.24)
project(2023_I)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(progra-3)

add_executable(2023_I progra-3/s4_chavez/Tarea1B/main.cpp progra-3/s4_chavez/Tarea1B/foo.cpp progra-3/s4_chavez/Tarea1B/foo.h)

add_executable(pcs progra-3/s4_chavez/p1-pc1.cpp)

add_executable(clasescpc CPC/Beginners_trainee/Sesions/codes1.cpp)

add_executable(vjudge CPC/Beginners_trainee/Contest_1/D.cpp)

add_executable(Cf CPC/Codeforces/Watermelon.cpp)

add_executable(mentoria Mentoria/sesion_2/funciones.cpp Mentoria/sesion_2/header.h)
