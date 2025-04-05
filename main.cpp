#include <iostream>
#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Headers/Global.hpp"
#include "Headers/DrawText.hpp"
#include "Headers/Pacman.hpp"
#include "Headers/Ghost.hpp"
#include "Headers/GhostManager.hpp"
#include "Headers/ConvertSketch.hpp"
#include "Headers/DrawMap.hpp"
#include "Headers/MapCollision.hpp"

int main() {

    bool game_won = 0;

    unsigned lag = 0;

    unsigned char level = 0;
    
    std::chrono::time_point<std::chrono::steady_clock> previous_time;

    std::array<std::string, MAP_HEIGHT> map_sketch = {
            " ################### ",
            " #........#........# ",
            " #o##.###.#.###.##o# ",
            " #.................# ",
            " #.##.#.#####.#.##.# ",
            " #....#...#...#....# ",
            " ####.### # ###.#### ",
            "    #.#   0   #.#    ",
            "#####.# ##=## #.#####",
            "     .  #123#  .     ",
            "#####.# ##### #.#####",
            "    #.#       #.#    ",
            " ####.# ##### #.#### ",
            " #........#........# ",
            " #.##.###.#.###.##.# ",
            " #o.#.....P.....#.o# ",
            " ##.#.#.#####.#.#.## ",
            " #....#...#...#....# ",
            " #.######.#.######.# ",
            " #.................# ",
            " ################### "
    };

    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

    std::array<Position, 4> ghost_positions;

    sf::Event event;
    
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "Pac-Man", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    GhostManager ghost_manager;
    Pacman pacman;

    srand(static_cast<unsigned>(time(0)));

    map = convert_sketch(map_sketch, ghost_positions, pacman);

    ghost_manager.reset(level, ghost_positions);
    
    previous_time = std::chrono::steady_clock::now();
    
    while (1 == window.isOpen()) {
        
        unsigned delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();
        
        lag += delta_time
        
        previous_time += std::chrono::microseconds(delta_time);
        
        while (FRAME_DURATION <= lag) {

            lag -= FRAME_DURATION;

            while (1 == window.pollEvent(event)) {

                switch (event.type) {

                    case sf::Event::Closed: {

                        window.close();
                    }
                }
            }
        }
    }
}
