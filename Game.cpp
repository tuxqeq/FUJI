#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game", sf::Style::Titlebar | sf::Style::Close);
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
    background = new Background("fudzimenu.png");
    newGamebutton = sf::RectangleShape(sf::Vector2f(120, 30));
    newGamebutton.setPosition(150, 225);
    textureNGButton.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Buttons/newgame.png");
    newGamebutton.setTexture(&textureNGButton);
    newGamebutton.setTextureRect(sf::IntRect(0, 0, 771, 161));
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
                if (newGamebutton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))) {
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
                }
            }
            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape) {
                    if(ingame){
                        newGame();
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
    if(character->minusheart) newLevel();
    if(character->health == 0) newGame();
    else character->update(time, window->getSize(), this->window);
    if(ingame) character->clevel->updateEnemies(time);
}

auto Game::render() -> void{
    window->clear(sf::Color(255, 0, 0, 255));
    window->draw(background->getBackground());
    if(not ingame) window->draw(newGamebutton);
    if(ingame) {
        level->draw(this->window, this->character->getOffsetXY());
        character->drawhealth(this->window);
        character->clevel->drawEnemies(window);
    }
    window->draw(character->sprite);
    window->display();
}

auto Game::newGame() -> void {
    background = new Background("fudzimenu.png");
    ingame = false;
    window->close();
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game",
                                  sf::Style::Titlebar | sf::Style::Close);
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
}

auto Game::newLevel() -> void {
    character->setPosition(75, window->getSize().y - 96);
    character->inGame = true;
    character->minusheart = false;
}
