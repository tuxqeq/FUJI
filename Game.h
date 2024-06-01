#include "Character.h"
#include "Background.h"
#pragma once

struct Game {
    sf::RenderWindow* window;
    sf::Event event;
    //Window* window;
    sf::RectangleShape newGamebutton;
    sf::Texture textureNGButton;
    Background* background;
    Character* character;
    bool ingame = false;

    Game();
    ~Game();
    bool running() const;
    auto pollEvents();
    auto update(float time) -> void;
    auto render() -> void;

};


