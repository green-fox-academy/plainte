cmake_minimum_required(VERSION 3.13)
project(blog)

set(CMAKE_CXX_STANDARD 14)

add_executable(blog main.cpp BlogPost.cpp BlogPost.h Blog.cpp Blog.h)