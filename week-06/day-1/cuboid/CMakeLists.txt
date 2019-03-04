cmake_minimum_required(VERSION 3.13)
project(cuboid)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Change this to the name of the directory that contains your code
set(PROJECT_LIB_NAME cuboid_lib)

# Change this to the name of the directory that contains your tests
set(PROJECT_TESTS_NAME cuboid_tests)

# Change this to the path where you extracted the Google Test files to
set(PATH_TO_GOOGLETEST "C:/Users/molna/Desktop/greenfox/googletest-release-1.8.1")

# Change this to your project name (optional)
set(PROJECT_NAME cuboid)

# The next line creates an executable file from main.cpp with the same name as your project
add_executable(${PROJECT_NAME} main.c)

# This block includes the subdirectories containing your code and tests
include_directories(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_TESTS_NAME})

# This line links your code to the main executable
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIB_NAME})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(SDL2_PATH "C:/SDL2-2.0.8/i686-w64-mingw32")
set(SDL2_IMAGE_PATH "C:/SDL2_image-2.0.3/i686-w64-mingw32")
set(SDL2_TTF_PATH "C:/SDL2_ttf-2.0.14/i686-w64-mingw32")
set(SDL2_GFX "C:/SDL2_plugins/gfx")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

include_directories(${SDL2_GFX}/inc)
file(GLOB gfx_inc "${SDL2_GFX}/inc/*.h")
file(GLOB gfx_src "${SDL2_GFX}/src/*.c")

add_executable(cuboid_function ${gfx_inc} ${gfx_src})

target_link_libraries(cuboid_function ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})