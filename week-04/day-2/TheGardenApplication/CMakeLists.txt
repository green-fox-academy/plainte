cmake_minimum_required(VERSION 3.13)
project(TheGardenApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(TheGardenApplication main.cpp Flower.cpp Flower.h Tree.cpp Tree.h Plant.cpp Plant.h Garden.cpp Garden.h)