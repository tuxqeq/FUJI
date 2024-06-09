#include "Character.h"
#include "Background.h"
#include "Level.h"
#include "Button.h"
#include <fmt/core.h>
#pragma once

struct Game {
    sf::RenderWindow* window;
    sf::Event event;
    sf::Font font;
    sf::Text text;
    //Window* window;
    sf::RectangleShape newGamebutton;
    int currentLevel;
    sf::Texture textureNGButton;
    Background* background;
    Character* character;
    Level* level;
    int CollectedCoins = 0;
    bool ingame = false;
    bool inmidlev = false;
    bool inlevFailed = false;
    Button* newGame;
    Button* continueGame;
    Button* nextLevel;
    Button* goToMainMenu;
    Button* restart;
    Button* restart2;
    Button* intstructions;

    Game();
    ~Game();
    bool running() const;
    auto pollEvents();
    auto update(float time) -> void;
    auto render() -> void;
    auto restartLevel() -> void;
    auto newLevel(int num) -> void;
    auto mainmenu() -> void;
    auto levelEnd() -> void;
    auto levelfailed() -> void;
};


