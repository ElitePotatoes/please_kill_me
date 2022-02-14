cmake_minimum_required(VERSION 3.20)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c libs/discrete_mathematics/first_laboratory_work/sets.c libs/discrete_mathematics/first_laboratory_work/sets.h)

add_subdirectory(libs)
target_link_libraries(course data_structures)
target_link_libraries(course algorithms)
target_link_libraries(course discrete_mathematics)
