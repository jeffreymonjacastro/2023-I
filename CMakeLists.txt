cmake_minimum_required(VERSION 3.24)
project(2023_I)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(2023_I Others/Hackerrank.cpp)

add_executable(tarea P3/S13/Tarea2b/tarea/foo.cpp P3/S13/Tarea2b/tarea/main.cpp)

add_executable(pcs P3/S15/PC3/p2.cpp)

add_executable(Dayane P3/s7/context.cpp)

add_executable(clasescpc CPC/Beginners_trainee/Sesions/codes1.cpp)

add_executable(vjudge CPC/Beginners_trainee/Contest_3/C.cpp)

#add_executable(Cf CPC/Codeforces/871/C.cpp)

add_executable(mentoria Mentoria/sesion_11/PC3_2022_2_Lab102.cpp)

add_executable(proyecto P3/Proyecto_maze/codes/main.cpp)

