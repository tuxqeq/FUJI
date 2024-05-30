#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game", sf::Style::Titlebar | sf::Style::Close);
    character = new Character(50, 400, 31, 32, "character.png");
    //window ->setFramerateLimit(120);
    background = new Background("back.png");
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
            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape) {
                    if(fullscreen){
                        fullscreen = false;
                        window->close();
                        window = new sf::RenderWindow(sf::VideoMode(800, 600), "game",
                                                      sf::Style::Titlebar | sf::Style::Close);
                    }
                    else {
                        window->close();
                        break;
                    }
                }
                if(event.key.code == sf::Keyboard::F8){
                    if(not fullscreen) {
                        fullscreen = true;
                        window->close();
                        window = new sf::RenderWindow(sf::VideoMode(800, 600), "game",
                                                      sf::Style::Titlebar | sf::Style::Close |
                                                      sf::Style::Fullscreen);
                    }
                }
            }
        }
    }
}

auto Game::update(float time) -> void{
    pollEvents();
    background->setSize(window->getSize());
    character->update(time, window->getSize());
}

auto Game::render() -> void{
    window->clear(sf::Color(255, 0, 0, 255));
    //character->update(time, window->getSize());
    window->draw(background->background);
    window->draw(character->sprite);
    window->display();
}