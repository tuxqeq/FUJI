#include "Background.h"

Background::Background(std::string name)
    : name(name){

    texture.loadFromFile("../assets/Backgrounds/" + name);
    textsize = texture.getSize();
    background.setTexture(texture);

    //background.setOrigin(size.x/2, size.y/2);
    background.setTextureRect(sf::IntRect(0, 0, 512, 341));
    //background.setPosition(50, 100);
}

void Background::setSize(sf::Vector2u vector2) {
    background.setScale(vector2.x/(textsize.x/1.), vector2.y/(textsize.y/1.));
}

sf::Sprite Background::getBackground() const {
    return background;
}