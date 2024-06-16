#pragma once
#include <iostream>
#include <random>
#include <sfml/Graphics.hpp>
#include <fmt/ranges.h>

struct Collectables {
    float x, y = 0;
    float curFrame;
    int frames = 0;
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
    bool collected;
    bool heal = false;
    bool hit = false;
    bool speed = false;

    Collectables();
    auto update(float time) -> void;
    auto draw(sf::RenderWindow* wnd) -> void;
    auto setPosition(float x, float y) -> void;
    auto setOffset(std::pair<float, float> pair) -> void;
    auto collect() -> void;
};

