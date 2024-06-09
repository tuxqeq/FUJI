#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game", sf::Style::Titlebar | sf::Style::Close);
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
    background = new Background("fudzimenu.png");
    /*newGamebutton = sf::RectangleShape(sf::Vector2f(120, 30));
    newGamebutton.setPosition(150, 225);
    textureNGButton.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Buttons/newgame.png");
    newGamebutton.setTexture(&textureNGButton);
    newGamebutton.setTextureRect(sf::IntRect(0, 0, 771, 161));*/
    newGame = new Button(150, 225, 120, 30, 720, 180, "newgame.png");
    continueGame = new Button(320, 225, 120, 30, 720, 180, "continue.png");
    nextLevel = new Button(130, 200, 120, 30, 720, 180, "nextlevel.png");
    goToMainMenu = new Button(300, 200, 120, 30, 720, 180, "mainmenu.png");
    restart = new Button(1550, 10, 32, 32, 320, 320, "restart.png");
    currentLevel = 0;
}

Game::~Game(){
    delete this->window;
}

bool Game::running() const {
    return window->isOpen();
}

auto Game::pollEvents() {
    while (window->pollEvent(event)){
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonPressed:{
                /*if (newGamebutton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))) {
                    newGamebutton.setFillColor(sf::Color::White);
                    if(not ingame) {
                        ingame = true;
                        window->close();
                        level = new Level(0);
                        window = new sf::RenderWindow(sf::VideoMode(1600, 768), "GameStarted",
                                                      sf::Style::Titlebar | sf::Style::Close);
                        character->setPosition(75, window->getSize().y - 96);
                        character->clevel = level;
                        character->inGame = true;

                    }
                }*/
                if(restart->isPressed(window)){
                    restartLevel();
                }

                if(inmidlev){
                    if(goToMainMenu->isPressed(window)){
                        mainmenu();
                    }
                    if(nextLevel->isPressed(window)){
                        currentLevel += 1;
                        newLevel(currentLevel);
                    }
                }

                if(newGame->isPressed(window)){
                    //fmt::print("new button");
                    /*if(not ingame) {
                        ingame = true;
                        window->close();
                        level = new Level(0);
                        window = new sf::RenderWindow(sf::VideoMode(1600, 768), "GameStarted",
                                                      sf::Style::Titlebar | sf::Style::Close);
                        character->setPosition(75, window->getSize().y - 96);
                        character->clevel = level;
                        character->inGame = true;

                    }*/
                    newLevel(currentLevel);
                }
                if(continueGame->isPressed(window)){
                    fmt::print("continue");
                }
            }
            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape) {
                    if(ingame or inmidlev){
                        mainmenu();
                    }
                    else {
                        window->close();
                        break;
                    }
                }
            }

        }
    }
}

auto Game::update(float time) -> void{
    pollEvents();
    background->setSize(window->getSize());
    if(character->minusheart) restartLevel();
    if(character->end) levelEnd();
    if(character->health == 0) mainmenu();
    else character->update(time, window->getSize(), this->window);
    if(ingame) character->clevel->updateEnemies(time);
}

auto Game::render() -> void{
    window->clear(sf::Color(255, 0, 0, 255));
    window->draw(background->getBackground());
    if(not ingame and not inmidlev) {
        window->draw(newGame->shape);
        window->draw(continueGame->shape);
    }
    else if(inmidlev){
        window->draw(nextLevel->shape);
        window->draw(goToMainMenu->shape);
    }
    else if(ingame) {
        level->draw(this->window, this->character->getOffsetXY());
        character->drawhealth(this->window);
        character->clevel->drawEnemies(window);
        window->draw(restart->shape);
    }
    window->draw(character->sprite);
    window->display();
}

auto Game::mainmenu() -> void {
    background = new Background("fudzimenu.png");
    inmidlev =  false;
    ingame = false;
    window->close();
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game",
                                  sf::Style::Titlebar | sf::Style::Close);
    delete character;
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
}

auto Game::restartLevel() -> void {
    character->setPosition(75, window->getSize().y - 96);
    character->offsetX = 0;
    character->inGame = true;
    character->minusheart = false;
}



auto Game::levelEnd() -> void {
    background = new Background("midlev.png");
    ingame = false;
    inmidlev = true;
    character->inGame = false;
    //character->saveScore();
    character->end = false;
    window->close();
    window = new sf::RenderWindow(sf::VideoMode(600, 400), "game",
                                  sf::Style::Titlebar | sf::Style::Close);
    character->setPosition(10000, 10000);

}

auto Game::newLevel(int num) -> void {
    if(not ingame or inmidlev) {
        inmidlev = false;
        ingame = true;
        window->close();
        level = new Level(num);
        window = new sf::RenderWindow(sf::VideoMode(1600, 768), "GameStarted",
                                      sf::Style::Titlebar | sf::Style::Close);
        delete character;
        character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
        character->inGame = true;
        character->clevel = level;
    }

}
