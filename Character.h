#include <sfml/Graphics.hpp>
//#include "Game.h"
#pragma once

struct Character {
    float x, y, w, h, speedY, speed, jumpH = 0;
    float jumpCooldown = 300, jumpTimer = 0;
    float hitCooldown = 300, hitTimer = 0;
    float grdlevel = 960;
    bool inGame;
    int dir=0;
    std::string name;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
    float frame, hitframe, crawlFrame = 0;
    Character(float x, float y, float w, float h, std::string name, bool inGame);
    auto crawlingAnim(float time, int dir, bool isOnGround) -> void;
    void collisionX(int num);
    auto update(float time, sf::Vector2u vector2) -> void;
    auto setPosition(float x, float y) -> void;


};


