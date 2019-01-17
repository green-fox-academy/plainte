cmake_minimum_required(VERSION 3.13)
project(compare_length)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(compare_length main.cpp)