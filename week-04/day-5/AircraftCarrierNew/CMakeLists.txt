cmake_minimum_required(VERSION 3.13)
project(AircraftCarrierNew)

set(CMAKE_CXX_STANDARD 14)

add_executable(AircraftCarrierNew main.cpp Aircraft.cpp Aircraft.h F16.cpp F16.h F35.cpp F35.h Carrier.cpp Carrier.h)