cmake_minimum_required(VERSION 3.12)
project(PacMan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(SFML 3.0 COMPONENTS System Window Graphics REQUIRED)

add_executable(PacMan Main.cpp Headers/Global.hpp
        Headers/ConvertSketch.hpp
        Headers/DrawMap.hpp
        Pacman.cpp
        Headers/Pacman.hpp
        Headers/MapCollision.hpp
        Headers/DrawText.hpp
        Headers/Ghost.hpp
        Headers/GhostManager.hpp
        DrawMap.cpp
        DrawText.cpp
        ConvertSketch.cpp
        Ghost.cpp
        GhostManager.cpp
        MapCollision.cpp)

target_link_libraries(PacMan PRIVATE SFML::System SFML::Window SFML::Graphics)

if(SFML_FOUND)
    message(STATUS "SFML ${SFML_VERSION_STRING} gefunden. Komponenten: System, Window, Graphics")
endif()