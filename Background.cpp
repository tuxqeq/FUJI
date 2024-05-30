#include "Background.h"

Background::Background(std::string name)
    : name(name){

    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Backgrounds/" + name);
    textsize = texture.getSize();
    background.setTexture(texture);

    //background.setOrigin(size.x/2, size.y/2);
    background.setTextureRect(sf::IntRect(0, 0, 400, 300));
    //background.setPosition(50, 100);
}

void Background::setSize(sf::Vector2u vector2) {
    background.setScale(vector2.x/400/*/textsize.x*/, vector2.y/300/*/textsize.y*/);
}

sf::Sprite Background::getBackground() const {
    return background;
}