#include <sfml/Graphics.hpp>
//#include "Game.h"
#pragma once

struct Character {
    float x, y, w, h, speedY, speed, jumpH = 0;
    float jumpCooldown = 300, jumpTimer = 0;
    float grdlevel = 0;
    int dir = 0;
    std::string name;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
    float frame;
    Character(float x, float y, float w, float h, std::string name);
    auto update(float time, sf::Vector2u vector2) -> void;
    //auto animation(float time, float speed, std::vector<sf::IntRect> vec);
    /*std::vector<sf::IntRect> standing = {
        sf::IntRect(0, 96, 0, 96),
        sf::IntRect(96, 96, 0, 96),
        sf::IntRect(192, 96, 0, 96),
        sf::IntRect(288, 96, 0, 96),
        sf::IntRect(384, 96, 0, 96),
        sf::IntRect(480, 96, 0, 96),
    };*/
    auto setPosition(float x, float y) -> void;
};


