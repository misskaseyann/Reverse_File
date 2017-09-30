cmake_minimum_required(VERSION 3.7)
project(ReverseFile)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES file_utils.h files_utils.c reverse.c)
add_executable(ReverseFile ${SOURCE_FILES})