#include "Collectables.h"
//TODO make heal
//TODO make speedup
//TODO make damage up
Collectables::Collectables() {
    std::random_device rd;
    int random = rd() % 4;

    switch (random) {
        case 0: {
            name = "coin.png";
            frames = 12;
            fmt::println("coin");
            break;
        }
        case 1: {
            name = "coin1.png";
            frames = 9;
            fmt::println("coin1");
            break;
        }
        case 2: {
            name = "coin2.png";
            frames = 12;
            fmt::println("coin2");
            break;
        }
        case 3: {
            name = "coin3.png";
            frames = 12;
            fmt::println("coin3");
            break;
        }
    }
    collected = false;
    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Level/" + name);
    sprite.setPosition(10000,10000*random);
    sprite.setTexture(texture);
    sprite.setScale(1.5, 1.5);
    x = 10000;
    y = 10000;
}
auto Collectables::update(float time) -> void {
    curFrame += time*0.009;
    if(curFrame > frames) curFrame -= frames;
    sprite.setTextureRect(sf::IntRect(16 * int(curFrame), 0, 16, 16));
}

auto Collectables::draw(sf::RenderWindow *wnd) -> void {
    wnd->draw(sprite);
}

auto Collectables::setPosition(float x, float y) -> void {
    sprite.setPosition(x, y - 48);
    this->x = x;
    this->y = y;
}

auto Collectables::setOffset(std::pair<float, float> pair) -> void {
    sprite.setPosition(x - pair.first, y-pair.second);
}

auto Collectables::collect() -> void{
    collected = true;
    x = 10000;
    y = 10000;
}

