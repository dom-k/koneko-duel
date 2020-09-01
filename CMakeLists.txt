cmake_minimum_required(VERSION 3.0)
project(koneko-duel)

set (CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/shape.cpp src/shape.h
    src/enemy.cpp src/enemy.h
    src/player.cpp src/player.h
    src/enemycontroller.cpp src/enemycontroller.h
    src/randomgenerator.cpp src/randomgenerator.h
    src/gamemanager.cpp src/gamemanager.h
)
