cmake_minimum_required(VERSION 3.13)
project(Devices)

set(CMAKE_CXX_STANDARD 14)

add_executable(Devices main.cpp Copier.cpp Copier.h
        Printer.cpp Printer.h Printer2D.cpp Printer2D.h Printer3D.cpp
        Printer3D.h Scanner.cpp Scanner.h )