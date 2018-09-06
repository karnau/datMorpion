cmake_minimum_required(VERSION 3.12)
project(datMorpion)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp MyWindow.cpp MyWindow.h)
target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics sfml-system)
