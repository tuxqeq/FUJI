#include <iostream>
#include <sfml/Graphics.hpp>

struct Character{
    float x, y, w, h, speedY, speed, jumpH;
    float jumpCooldown = 500, jumpTimer = 0;
    int dir = 0;
    std::string name;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
    float frame;
    Character(float x, float y, float w, float h, std::string name) : x(x), y(y), w(w), h(h), name(name){
        image.loadFromFile("/Users/tuxqeq/Documents/CLion/TryingProject/assets/" + name);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, w, h));
        sprite.setPosition(x, y);
        jumpH = 0;
    }
    auto update(float time) -> void{
        x += speed*time;
        y -= speedY;
        jumpH += speedY;
        sprite.setPosition(x, y);
        speed = 0;
        jumpTimer += time;
        if( jumpH > 60){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) speedY = -0.3;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) speedY = -0.2;
            else speedY = -0.5;

        }
        if(jumpH < 0){
            speedY = 0;
        }
        bool ableToJump = false;
        if(jumpH <= 0 and jumpTimer > jumpCooldown){
            ableToJump = true;
        }
        //speedY = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and ableToJump){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) speedY = 0.3;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) speedY = 0.2;
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
            sprite.setTextureRect(sf::IntRect(31*int(frame), 64, 31, 32));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            //dir = 2;
            speed = 0.4;
            frame += 0.02f * time;
            if(frame > 3) frame -= 3;
            sprite.setTextureRect(sf::IntRect(31*int(frame), 32, 31, 32));

        }
        else {
            frame += 0.009f * time;
            if(frame > 2) frame -= 2;
            sprite.setTextureRect(sf::IntRect(31*int(frame), 0, 31, 32));
        }
    }
};

struct Game{
    sf::RenderWindow* window;
    sf::Event event;
    //Window* window;
    Character* character;
    bool fullscreen = false;
    Game(){
        character = new Character(50, 500, 31, 32, "character.png");
        window = new sf::RenderWindow(sf::VideoMode(800, 600), "game", sf::Style::Titlebar | sf::Style::Close);
    }
    ~Game(){
        delete this->window;
    }

    bool running() const{
        return window->isOpen();
    }

    auto pollEvents(){
        bool anyKeyPressed;
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
    }
    auto render(float time) -> void{
        window->clear(sf::Color(0, 0, 0, 255));
        character->update(time);
        window->draw(character->sprite);
        window->display();
    }
};



auto main()  -> int{
    sf::Clock clock;
    Game game;
    while (game.running()){
        float time = clock.getElapsedTime().asMicroseconds();
        time = time / 1500;
        clock.restart();
        game.update();
        game.render(time);
    }
}
//хуйня не рабоает
