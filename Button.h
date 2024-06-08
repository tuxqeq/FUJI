#pragma once
#include <sfml/Graphics.hpp>

struct Button {
    sf::Texture texture;
    sf::RectangleShape shape;
    float x, y;
    Button(float x, float y, int width, int length, int rectwidth, int rectheight, std::string name);
    auto isPressed(sf::RenderWindow* wnd) -> bool;
};


