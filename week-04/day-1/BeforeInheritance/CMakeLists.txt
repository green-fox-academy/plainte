cmake_minimum_required(VERSION 3.13)
project(BeforeInheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(BeforeInheritance main.cpp Person.cpp Person.h Student.cpp Student.h Mentor.cpp Mentor.h Sponsor.cpp Sponsor.h)