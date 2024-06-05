#pragma once
#include <iostream>
#include <map>
#include <sfml/Graphics.hpp>
#include "Background.h"


struct Level {
    Background* background;
    sf::Sprite shape;
    sf::Texture texture;
    sf::Texture spike;
    int num;
    Level(int num);
    static std::vector<std::vector<std::string>> levels;
    std::vector<std::string> curlevel;
    auto draw(sf::RenderWindow* wnd, std::pair<float, float> pair) -> void;
    ~Level();
};


