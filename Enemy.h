#pragma once
#include <sfml/Graphics.hpp>
//#include "Level.h"

struct Enemy {
    float x, y, speed = 0;
    float curFrame;
    float deadtimer = 3;
    sf::Sprite sprite;
    sf::Texture texture;
    bool life;
    Enemy(std::string name, float speed, float x, float y);
    auto update(float time) -> void;
    auto collision() -> void;
    auto draw(sf::RenderWindow* wnd) -> void;
    auto setPosition(float x, float y) -> void;
    auto setOffset(std::pair<float, float> pair) -> void;
};



