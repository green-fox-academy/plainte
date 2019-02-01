cmake_minimum_required(VERSION 3.13)
project(Pirate)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pirate main.cpp Pirate.cpp Pirate.h PirateNames.h Ship.cpp Ship.h)