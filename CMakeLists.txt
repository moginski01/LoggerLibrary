cmake_minimum_required(VERSION 3.17)
project(LoggerProject C)

set(CMAKE_C_STANDARD 11)
SET(CMAKE_C_FLAGS -pthread)

add_executable(LoggerProject main.c log.c log.h)