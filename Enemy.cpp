#include "Enemy.h"

Enemy::Enemy(std::string name, float speed, float x, float y) : speed(speed), x(x), y(y){
    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Enemies/" + name);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(2, 2);
    life = true;
}

auto Enemy::update(float time) -> void {
    x = speed * time;

    //collision();
    deadtimer += time * 0.005;
    curFrame += time * 0.005;
    if (curFrame > 4) curFrame-= 4;
    sprite.setTextureRect(sf::IntRect(24*int(curFrame), 0, 24, 24));
    if (!life) {
        sprite.setTextureRect(sf::IntRect(48, 48, 24, 24));
        deadtimer = 0;
    }
    /*if(deadtimer == 2){
        sprite.setTextureRect(sf::IntRect (0, 0, 10, 10));
    }*/
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





