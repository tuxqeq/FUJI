#include "Character.h"
#include <fmt/core.h>

Character::Character(float x, float y, float w, float h, std::string name)
        : x(x), y(y), w(w), h(h), name(name){
    image.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Character/" + name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
    //sprite.setScale(1.5, 1.5);
    sprite.setPosition(x, y);
    jumpH = 0;
    grdlevel = y;
}
bool jumping = false;
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
        x = -45;
    }
    if(x < -45){
        x = vector2.x;
    }
    if(jumping){
        frame += 0.02f * time;
        if (frame > 8) frame -= 8;
        sprite.setTextureRect(sf::IntRect(96 *int(frame), 672, 96, 96));
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
        jumping = false;
    }
    if(y == grdlevel){
        isOnGround = true;
        jumping = false;
    }
    if(isOnGround and jumpTimer > jumpCooldown){
        ableToJump = true;
    }
    //speedY = 0;
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and ableToJump){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) speedY = 0.4;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) speedY = 0.3;
        else speedY = 0.5;
        jumping = true;
        jumpTimer = 0;
        frame += 0.02f * time;
        if (frame > 8) frame -= 8;
        sprite.setTextureRect(sf::IntRect(96 * int(frame), 672, 96, 96));
        if(jumpH > 70){
            speedY = 0;
            sprite.setTextureRect(sf::IntRect(384, 672, 96, 96));
        }

    }if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        //dir = 1;
        speed = -0.3;
        if(isOnGround) {
            frame -= 0.02f * time;
            if (frame < 0) frame += 8;
            sprite.setTextureRect(sf::IntRect(96 * int(frame), 96, 96, 96));
        }/*else{
            //if (frame < 0) frame += 8;
            //sprite.setTextureRect(sf::IntRect(96 * int(frame), 672, 96, 96));
        }*/

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        //dir = 2;
        speed = 0.4;
        if(isOnGround) {
            //fmt::println("hui");
            frame += 0.02f * time;
            if (frame > 6) frame -= 6;
            sprite.setTextureRect(sf::IntRect(96 * int(frame), 192, 96, 96));
        } /*else {
            //if (frame > 8) frame -= 8;
            //sprite.setTextureRect(sf::IntRect(96 * int(frame), 672, 96, 96));
        }*/
    }else if(not jumping){
        frame += 0.009f * time;
        if(frame > 6) frame -= 6;
        sprite.setTextureRect(sf::IntRect(96*int(frame), 0, 96, 96));
    }
}

auto Character::setPosition(float x, float y) -> void {
    sprite.setPosition(x, y);
    this->x = x;
    this->y = y;
    grdlevel = y;
}


