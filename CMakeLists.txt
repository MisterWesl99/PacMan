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

# Define the source resources directory
set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/Resources)

# Define the destination directory (where the executable is)
set(DESTINATION_DIR ${CMAKE_BINARY_DIR}/Resources) # or ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources if you customized output dirs

# Copy the entire Resources directory if it exists
if(EXISTS ${RESOURCE_DIR})
    message(STATUS "Copying Resources from ${RESOURCE_DIR} to ${DESTINATION_DIR}")
    file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})
    # If you only want specific files, use configure_file or file(COPY...) for each
    # Example for just the image:
    # file(COPY ${RESOURCE_DIR}/Images/Map16.png DESTINATION ${DESTINATION_DIR}/Images/)
else()
    message(WARNING "Resources directory not found at ${RESOURCE_DIR}")
endif()

target_link_libraries(PacMan PRIVATE SFML::System SFML::Window SFML::Graphics)

if(SFML_FOUND)
    message(STATUS "SFML ${SFML_VERSION_STRING} gefunden. Komponenten: System, Window, Graphics")
endif()