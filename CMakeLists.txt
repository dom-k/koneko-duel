cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(koneko-duel)

add_executable(
        koneko-duel
        src/main.cpp
        src/Player.cpp src/Player.h
        src/LifeForm.cpp src/LifeForm.h
        src/Component/Component.cpp src/Component/Component.h
        src/Component/PlayerCreationComponent.cpp src/Component/PlayerCreationComponent.h src/Component/MainMenuComponent.cpp src/Component/MainMenuComponent.h)
