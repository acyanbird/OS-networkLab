cmake_minimum_required(VERSION 3.20)
project(lab1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1 dePrime.c swap.c sort.c alloc.c)

add_executable(dePrime dePrime.c prime.c main.c)

target_link_libraries(dePrime.c m)