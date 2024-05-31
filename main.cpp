#include <iostream>
#include <sfml/Graphics.hpp>
#include "Game.h"
/*
struct Character{
    float x, y, w, h, speedY, speed, jumpH = 0;
    float jumpCooldown = 500, jumpTimer = 0;
    float grdlevel = 0;
    int dir = 0;
    std::string name;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
    float frame;
    Character(float x, float y, float w, float h, std::string name) : x(x), y(y), w(w), h(h), name(name){
        image.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/" + name);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, w, h));
        sprite.setScale(1.5, 1.5);
        sprite.setPosition(x, y);
        jumpH = 0;
        grdlevel = y;
    }
    auto update(float time, sf::Vector2u vector2) -> void {
        x += speed*time;
        y -= speedY*time;
        jumpH += speedY*time;
        sprite.setPosition(x, y);
        speed = 0;
        jumpTimer += time;
        if (x > vector2.x){
            x = 0;
        }
        if(x < -25){
            x = vector2.x;
        }
        if( jumpH > 60){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) speedY = -0.4;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) speedY = -0.3;
            else speedY = -0.5;

        }
        if(jumpH < 0){
            speedY = 0;
            y = grdlevel;
        }
        bool ableToJump = false;
        bool isOnGround = false;
        if(y == grdlevel){
            isOnGround = true;
        }
        if(isOnGround and jumpTimer > jumpCooldown){
            ableToJump = true;
        }
        //speedY = 0;
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and ableToJump){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) speedY = 0.4;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) speedY = 0.3;
            else speedY = 0.5;
            jumpTimer = 0;
            sprite.setTextureRect(sf::IntRect(31, 0, 31, 32));
            if(jumpH > 60){
                speedY = 0;
                sprite.setTextureRect(sf::IntRect(0, 0, 31, 32));
            }

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            //dir = 1;
            speed = -0.3;
            frame += 0.02f * time;
            if(frame > 3) frame -= 3;
            if(isOnGround)
                sprite.setTextureRect(sf::IntRect(31*int(frame), 64, 31, 32));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            //dir = 2;
            speed = 0.4;
            frame += 0.02f * time;
            if(frame > 3) frame -= 3;
            if(isOnGround)
                sprite.setTextureRect(sf::IntRect(31*int(frame), 32, 31, 32));

        }
        else {
            frame += 0.009f * time;
            if(frame > 2) frame -= 2;
            sprite.setTextureRect(sf::IntRect(31*int(frame), 0, 31, 32));
        }
    }
};

struct Background{
    sf::Sprite background;
    std::string name;
    Background(std::string name) : name(name){
        sf::Texture texture;
        sf::Image image;
        image.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Backgrounds/" + name);
        texture.loadFromImage(image);
        background.setTexture(texture);
        background.setTextureRect(sf::IntRect(0, 0, 512, 240));
    }

    void setSize(sf::Vector2u vector2) {
        background.setScale(vector2.x, vector2.y);
    }
    sf::Sprite& getSprite() {
        return background;
    }
};

struct Game{
    sf::RenderWindow* window;
    sf::Event event;
    //Window* window;
    Background* background;
    Character* character;
    bool fullscreen = false;
    Game(){
        window = new sf::RenderWindow(sf::VideoMode(800, 600), "game", sf::Style::Titlebar | sf::Style::Close);
        character = new Character(50, 500, 31, 32, "ninja.png");
        window ->setFramerateLimit(120);
        background = new Background("back.png");
    }
    ~Game(){
        delete this->window;
    }

    bool running() const{
        return window->isOpen();
    }

    auto pollEvents(){
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

    auto update() -> void{
        pollEvents();
        //background->setSize(window->getSize());
    }
    auto render(float time) -> void{
        window->clear(sf::Color(255, 0, 0, 255));
        character->update(time, window->getSize());
        window->draw(background->getSprite());
        window->draw(character->sprite);
        window->display();
    }
};

*/


auto main()  -> int{
    sf::Clock clock;
    Game game;
    while (game.running()){
        float time = clock.getElapsedTime().asMicroseconds();
        time = time / 1500;
        clock.restart();
        game.update(time);
        game.render();
    }
}
//хуйня не рабоает
