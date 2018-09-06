cmake_minimum_required(VERSION 3.12)
project(datMorpion)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp src/windowManaging/MyWindow.cpp src/windowManaging/MyWindow.hpp src/windowManaging/GameBoard.cpp src/windowManaging/GameBoard.hpp src/windowManaging/PlayerEnum.hpp src/windowManaging/Cell.cpp src/windowManaging/Cell.hpp)
target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics sfml-system)
