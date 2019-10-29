cmake_minimum_required(VERSION 3.15)
project(Caso010 C)

set(CMAKE_C_STANDARD 99)

add_executable(Caso010 main.c Matroid.cpp Matroid.h matroidEvaluator.cpp matroidEvaluator.h)