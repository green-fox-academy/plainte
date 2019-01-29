cmake_minimum_required(VERSION 3.13)
project(post_it)

set(CMAKE_CXX_STANDARD 14)

add_executable(post_it main.cpp cmake-build-debug/PostIt.cpp cmake-build-debug/PostIt.h)