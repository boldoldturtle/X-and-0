cmake_minimum_required(VERSION 3.21)
project(tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(tests tests.cpp doctest.h)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/ASUS/Desktop/untitled2/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/Users/ASUS/Desktop/untitled2/SFML/include)
target_link_libraries(tests sfml-system sfml-window sfml-graphics sfml-audio)