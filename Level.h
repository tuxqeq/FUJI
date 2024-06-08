#pragma once
#include <iostream>
#include <random>
#include <map>
#include <sfml/Graphics.hpp>
#include "Background.h"
#include "Enemy.h"

struct Level {
    Background* background;
    sf::Sprite shape;
    sf::Texture texture;
    sf::Texture spike;
    //Enemy* enemy;
    std::vector<Enemy*> enemies;
    int num;
    Level(int num);
    //std::vector<Enemy> enemies;
    int numOfEnemy = 0;
    static std::vector<std::vector<std::string>> levels;
    std::vector<std::string> curlevel;
    auto draw(sf::RenderWindow* wnd, std::pair<float, float> pair) -> void;
    auto updateEnemies(float time) -> void;
    auto drawEnemies(sf::RenderWindow* wnd) -> void;
    ~Level();
};


