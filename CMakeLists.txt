cmake_minimum_required(VERSION 3.0)
project(koneko-duel)

# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package (SQLite3)

add_executable(
        koneko-duel
        src/main.cpp
        src/Player.cpp src/Player.h
        src/LifeForm.cpp src/LifeForm.h
        src/DatabaseAdapter.cpp src/DatabaseAdapter.h
        src/Component/Component.cpp src/Component/Component.h
        src/Component/PlayerCreationComponent.cpp src/Component/PlayerCreationComponent.h src/Component/MainMenuComponent.cpp src/Component/MainMenuComponent.h src/Component/DuelComponent.cpp src/Component/DuelComponent.h src/Enemy.h src/Carpa.cpp src/Carpa.h src/GameController.cpp src/GameController.h src/Component/WorldMapComponent.cpp src/Component/WorldMapComponent.h)

if (SQLITE3_FOUND)
  include_directories(${SQLITE3_INCLUDE_DIRS})
  target_link_libraries (koneko-duel ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)
