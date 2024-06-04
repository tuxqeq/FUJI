#pragma once
#include <iostream>
#include <map>
#include <sfml/Graphics.hpp>
#include "Background.h"
#include "Character.h"


struct Level {
    Background* background;
    Character* character;
    sf::Sprite shape;
    sf::Texture texture;
    sf::Texture spike;
    Level(Character* character);
    static std::vector</*std::vector<*/std::string> levels;
    auto draw(int level, sf::RenderWindow* wnd, std::pair<float, float> pair) -> void;

};


