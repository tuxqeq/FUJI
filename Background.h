#include <sfml/Graphics.hpp>
#pragma once

struct Background {
    sf::Sprite background;
    std::string name;
    sf::Texture texture;
    sf::Image image;
    sf::Vector2u textsize;
    Background(std::string name);


    void setSize(sf::Vector2u vector2);

    sf::Sprite getBackground() const;
};
