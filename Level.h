#pragma once
#include <iostream>
#include <random>
#include <map>
#include <sfml/Graphics.hpp>
#include "Background.h"
#include "Collectables.h"
#include "Enemy.h"

struct Level {
    Background* background;
    sf::Sprite shape;
    sf::Texture texture;
    sf::Texture spike;
    sf::Texture cloud;
    std::vector<Enemy*> enemies;
    std::vector<Collectables*> coins;
    int num;
    Level(int num);
    int numOfEnemy = 0;
    int numOfCoin = 0;
    int coinsInCave = 0;
    static std::vector<std::vector<std::string>> levels;
    std::vector<std::string> curlevel;
    auto draw(sf::RenderWindow* wnd, std::pair<float, float> pair) -> void;
    auto updateEnemies(float time) -> void;
    auto updateCoins(float time) -> void;
    auto drawEnemies(sf::RenderWindow* wnd) -> void;
    auto drawCoins(sf::RenderWindow* wnd) -> void;
    ~Level();
};


