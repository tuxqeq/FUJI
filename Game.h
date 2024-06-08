#include "Character.h"
#include "Background.h"
#include "Level.h"
#include "Button.h"
#include <fmt/core.h>
#pragma once

struct Game {
    sf::RenderWindow* window;
    sf::Event event;
    //Window* window;
    sf::RectangleShape newGamebutton;
    sf::Texture textureNGButton;
    Background* background;
    Character* character;
    Level* level;
    bool ingame = false;
    bool inmidlev = false;
    Button* newGame;
    Button* continueGame;
    Button* nextLevel;
    Button* goToMainMenu;
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
};


