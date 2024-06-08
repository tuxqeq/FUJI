#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game", sf::Style::Titlebar | sf::Style::Close);
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
    //window ->setFramerateLimit(120);
    background = new Background("fudzimenu.png");
    newGamebutton = sf::RectangleShape(sf::Vector2f(120, 30));
    newGamebutton.setPosition(150, 225);
    //newGamebutton.setFillColor(sf::Color::Green);
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
                        /*background = new Background(".png");*/
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
                        /*background = new Background("fudzimenu.png");
                        ingame = false;
                        window->close();
                        window = new sf::RenderWindow(sf::VideoMode(800, 600), "game",
                                                      sf::Style::Titlebar | sf::Style::Close);
                        character->setPosition(10, window->getSize().y/1.f - 200);
                        character->inGame=false;*/
                        newGame();
                    }
                    else {
                        window->close();
                        break;
                    }
                }
                /*if(event.key.code == sf::Keyboard::F5) {
                    if(not ingame) {
                        background = new Background("back.png");
                        ingame = true;
                        window->close();
                        window = new sf::RenderWindow(sf::VideoMode(1000, 800), "GameStarted",
                                                      sf::Style::Titlebar | sf::Style::Close);
                        character->setPosition(75, window->getSize().y - 200);
                        character->inGame = true;
                    }
                }*/
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
    if(ingame){ character->clevel->enemy->update(time); }
}

auto Game::render() -> void{
    window->clear(sf::Color(255, 0, 0, 255));
    //character->update(time, window->getSize());
    window->draw(background->getBackground());
    if(not ingame) window->draw(newGamebutton);
    if(ingame) {
        level->draw(this->window, this->character->getOffsetXY());
        character->drawhealth(this->window);
        window->draw(character->clevel->enemy->sprite);
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
    /*character->setPosition(10, window->getSize().y/1.f - 200);
    character->inGame=false;
    character->health = 5;*/
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
    /*for(int i; i < 17; i++){
        Level::curlevel[i] = Level::levels[level->num][i];
    }*/
}

auto Game::newLevel() -> void {
    //window->close();
    level = new Level(0);
    //window = new sf::RenderWindow(sf::VideoMode(1600, 768), "GameStarted",
                                  //sf::Style::Titlebar | sf::Style::Close);
    character->setPosition(75, window->getSize().y - 96);
    character->clevel = level;
    character->inGame = true;
    character->minusheart = false;
    /*for(int i = 0; i < 17; i++){
        Level::curlevel[i] = Level::levels[level->num][i];
    }*/
}
