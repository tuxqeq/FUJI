#include <iostream>
#include <sfml/Graphics.hpp>
#include "Game.h"

auto main()  -> int{
    sf::Clock clock;
    Game game;
    while (game.running()){
        float time = clock.getElapsedTime().asMicroseconds();
        time = time / 1500;
        clock.restart();
        game.update(time);
        game.render();
    }
}
