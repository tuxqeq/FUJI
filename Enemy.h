#pragma once
#include <sfml/Graphics.hpp>
//#include "Level.h"

struct Enemy {
    float x, y, speed = 0;
    float curFrame;
    float deadtimer = 4;
    sf::Sprite sprite;
    sf::Texture texture;
    int health = 0;
    bool life;
    float road = 0;
    int maxlen = 200;
    Enemy(std::string name, float speed, float x, float y, int health);
    auto update(float time) -> void;
    //auto collision() -> void;
    auto draw(sf::RenderWindow* wnd) -> void;
    auto setPosition(float x, float y) -> void;
    auto setText(std::string name) -> void;
    auto setOffset(std::pair<float, float> pair) -> void;
    auto enemyhit() -> void;
};



