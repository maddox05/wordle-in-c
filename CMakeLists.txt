cmake_minimum_required(VERSION 3.25)
project(wordle C)

set(CMAKE_C_STANDARD 11)

add_executable(wordle wordle.c library/cs50.c wordle.c)