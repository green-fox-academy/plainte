cmake_minimum_required(VERSION 3.13)
project(GF_inheritance_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(GF_inheritance_exercise main.cpp Person.h Person.cpp Student.cpp Student.h Mentor.cpp Mentor.h Sponsor.cpp Sponsor.h Cohort.cpp Cohort.h)