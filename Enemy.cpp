#include "Enemy.h"

Enemy::Enemy(std::string name, float speed, float x, float y, int health) : speed(speed), x(x), y(y), health(health){
    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Enemies/" + name);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(2, 2);
    life = true;
}


auto Enemy::setText(std::string name) -> void {
    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Enemies/" + name);
    sprite.setTexture(texture);
}

auto Enemy::update(float time) -> void {
    x += speed * time;
    road += std::abs(speed) * time;
    if(road > maxlen) {
        speed = -speed;
        road = 0;
    }
    //collision();
    deadtimer += time * 0.009;
    curFrame += time * 0.009;
    if (curFrame > 4) curFrame-= 4;
    sprite.setTextureRect(sf::IntRect(24*int(curFrame), 0, 24, 24));
    if (not life) {
        sprite.setTextureRect(sf::IntRect(48, 48, 24, 24));
        deadtimer = 0;
    }
    if(deadtimer < 4){
        sprite.setTextureRect(sf::IntRect(48, 48, 24, 24));
    }
}

auto Enemy::draw(sf::RenderWindow* wnd) -> void {
    wnd->draw(sprite);
}

auto Enemy::setPosition(float x, float y) -> void {
    sprite.setPosition(x, y - 48);
    this->x = x;
    this->y = y;

}

auto Enemy::setOffset(std::pair<float, float> pair) -> void {
    sprite.setPosition(x - pair.first, y-pair.second);
}



auto Enemy::enemyhit() -> void {
    health -= 1;
    fmt::println("{}", health);
    if(health == 0){
        life = false;
        deadtimer = 0;
        x = 10000;
        y = 10000;
    }
}





