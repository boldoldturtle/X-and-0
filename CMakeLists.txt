cmake_minimum_required(VERSION 3.0)
project(untitled2)
set(CMAKE_CXX_STANDARD 11)

add_executable(
        untitled2 main.cpp
        objects/game1.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/ASUS/Desktop/untitled2/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/Users/ASUS/Desktop/untitled2/SFML/include)
target_link_libraries(untitled2 sfml-system sfml-window sfml-graphics sfml-audio)
