#include "Character.h"
#include "Background.h"
#pragma once

struct Game {
    sf::RenderWindow* window;
    sf::Event event;
    //Window* window;
    Background* background;
    Character* character;
    bool fullscreen = false;

    Game();
    ~Game();
    bool running() const;
    auto pollEvents();
    auto update(float time) -> void;
    auto render() -> void;

};


