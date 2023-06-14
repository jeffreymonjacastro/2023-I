cmake_minimum_required(VERSION 3.24)
project(2023_I)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(2023_I P3/S12/LabA/Ejercicio004.cpp)

add_executable(tarea P3/s9/tarea2a/tarea/main.cpp P3/s9/tarea2a/tarea/foo.cpp)

add_executable(pcs P3/s10/PC2_practice/pc2_2022_2.cpp)

add_executable(Dayane P3/s7/context.cpp)

add_executable(clasescpc CPC/Beginners_trainee/Sesions/codes1.cpp)

add_executable(vjudge CPC/Beginners_trainee/Contest_3/C.cpp)

add_executable(Cf CPC/Codeforces/Watermelon.cpp)

add_executable(mentoria Mentoria/sesion_9/teoria.cpp)

