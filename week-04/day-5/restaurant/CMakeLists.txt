cmake_minimum_required(VERSION 3.13)
project(restaurant)

set(CMAKE_CXX_STANDARD 14)

add_executable(restaurant main.cpp Employees.cpp Employees.h Waiter.cpp Waiter.h Chef.cpp Chef.h Manager.cpp Manager.h Restaurant.cpp Restaurant.h)