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
    Level(int num);
    static std::vector<std::vector<std::string>> levelll;
    static std::vector<std::string> levels;
    static std::vector<std::string> level1;
    auto draw(sf::RenderWindow* wnd, std::pair<float, float> pair) -> void;

};


