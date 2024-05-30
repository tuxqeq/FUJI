#include "Character.h"

Character::Character(float x, float y, float w, float h, std::string name)
        : x(x), y(y), w(w), h(h), name(name){
    image.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/" + name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
    sprite.setScale(1.5, 1.5);
    sprite.setPosition(x, y);
    jumpH = 0;
    grdlevel = y;
}

auto Character::update(float time, sf::Vector2u vector2) -> void {
    x += speed*time;
    y -= speedY*time;
    jumpH += speedY*time;
    bool ableToJump = false;
    bool isOnGround = false;
    sprite.setPosition(x, y);
    speed = 0;
    jumpTimer += time;
    if (x > vector2.x){
        x = 0;
    }
    if(x < -25){
        x = vector2.x;
    }
    if( jumpH > 70){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) speedY = -0.4;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) speedY = -0.3;
        else speedY = -0.5;
    }
    if(jumpH < 0){
        speedY = 0;
        y = grdlevel;
        isOnGround = true;

    }

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
        if(jumpH > 70){
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
