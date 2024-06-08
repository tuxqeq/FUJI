#include "Button.h"


Button::Button(float x, float y, int width, int length, int rectwidth, int rectheight, std::string name) {
    shape = sf::RectangleShape(sf::Vector2f(width, length));
    shape.setPosition(x, y);
    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Buttons/" + name);
    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(0, 0, rectwidth, rectheight));
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color(255, 32, 161, 200));
}

auto Button::isPressed(sf::RenderWindow *wnd) -> bool {
    return shape.getGlobalBounds().contains(wnd->mapPixelToCoords(sf::Mouse::getPosition(*wnd)));
}

