#include <sfml/Graphics.hpp>
#include "Level.h"
//#include "Game.h"
#pragma once

struct Character {
    float x, y, w, h, speedY, speed, jumpH = 0;
    float jumpCooldown = 500, jumpTimer = 0;
    float hitCooldown = 300, hitTimer = 0;
    float offsetX = 0, offsetY = 0;
    float grdlevel = 960;
    bool minusheart = false;
    int health = 5;
    bool inGame;
    int dir=0;
    std::vector<sf::Sprite> hearts;
    Level* clevel;
    std::string name;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture heart;
    float frame, hitframe, crawlFrame = 0;
    Character(float x, float y, float w, float h, std::string name, bool inGame);
    auto crawlingAnim(float time, int dir, bool isOnGround) -> void;
    void collisionX(int num);
    auto update(float time, sf::Vector2u vector2, sf::RenderWindow* wnd) -> void;
    auto setPosition(float x, float y) -> void;
    auto getXY() -> std::pair<float, float>;
    auto drawhealth(sf::RenderWindow* wnd) -> void;
};


