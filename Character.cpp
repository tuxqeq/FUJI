#include "Character.h"
#include <fmt/core.h>
//TODO create animation class and handle animations there
//TODO implement crawling
Character::Character(float x, float y, float w, float h, std::string name, bool inGame)
        : x(x), y(y), w(w), h(h), name(name), inGame(inGame){
    image.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Character/" + name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
    sprite.setScale(0.75, 0.75);
    sprite.setPosition(x, y);
    jumpH = 0;
    grdlevel = y;
}
bool jumping = false;
bool hit = false;
bool crawling = false;
auto Character::update(float time, sf::Vector2u vector2) -> void {
    x += speed*time;
    y -= speedY*time;
    jumpH += speedY*time;
    bool ableToJump = false;
    bool isOnGround = false;
    sprite.setPosition(x, y);
    speed = 0;
    jumpTimer += time;
    hitTimer += time;
    if (x > vector2.x and not inGame){
        x = -45;
    }
    if(x < -45 and not inGame){
        x = vector2.x;
    }
    if(jumping){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) speedY -= 0.025f*time;
        speedY -= 0.005f*time;
        if(dir == 1) {
            frame += 0.02f * time;
            if (frame > 8) frame -= 8;
            sprite.setTextureRect(sf::IntRect(96 * int(frame) + 96, 672, -96, 96));
        }else{
            frame += 0.02f * time;
            if (frame > 8) frame -= 8;
            sprite.setTextureRect(sf::IntRect(96 * int(frame), 672, 96, 96));
        }
    }
    if(jumpH <= 0){
        speedY = 0;
        y = grdlevel;
        isOnGround = true;
        jumping = false;
    }
    if(isOnGround and jumpTimer > jumpCooldown){
        ableToJump = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) and not jumping){
        hit = true;
    }
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and ableToJump){
        speedY = 0.8;
        jumping = true;
        jumpTimer = 0;

    }if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        dir = 1;
        speed = -0.4;
        if(isOnGround) {
            frame += 0.02f * time;
            if (frame > 6) frame -= 6;
            sprite.setTextureRect(sf::IntRect(96 * int(frame) + 96, 192, -96, 96));
        }
        if(isOnGround and hit and hitTimer > hitCooldown){
            speed = 0;
            hitframe += 0.009f * time;
            if (hitframe > 4) {
                hitframe -= 4;
                hit = false;
                hitTimer = 0;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(hitframe)+96, 576, -96, 96));
        }
        /*if(isOnGround and (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
            speed = -0.2;
            crawling = true;
            while (crawlFrame < 5){
                crawlFrame += 0.009f * time;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame), 288, 96, 96));
        }else if (crawling){
            crawlFrame += 0.05f * time;
            if(crawlFrame > 9) {
                crawling = false;
                crawlFrame -= 9;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame) + 96, 288, -96, 96));

        }*/
        crawlingAnim(time, dir, isOnGround);

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        dir = 0;
        speed = 0.4;
        if(isOnGround) {
            frame += 0.02f * time;
            if (frame > 6) frame -= 6;
            sprite.setTextureRect(sf::IntRect(96 * int(frame), 192, 96, 96));
        }
        if(isOnGround and hit and hitTimer > hitCooldown){
            speed = 0;
            hitframe += 0.009f * time;
            if (hitframe > 4) {
                hitframe -= 4;
                hit = false;
                hitTimer = 0;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(hitframe), 576, 96, 96));
        }
        /*if(isOnGround and (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
            speed = 0.2;
            crawling = true;
            while (crawlFrame < 5){
                crawlFrame += 0.009f * time;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame), 288, 96, 96));
        }else if (crawling){
            crawlFrame += 0.05f * time;
            if(crawlFrame > 9) {
                crawling = false;
                crawlFrame -= 9;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame), 288, 96, 96));
        }*/
        crawlingAnim(time, dir, isOnGround);
    }else if(not jumping){
        frame += 0.009f * time;
        if(frame > 6) frame -= 6;
        if(dir == 1) sprite.setTextureRect(sf::IntRect(96*int(frame) + 96, 0, -96, 96));
        else sprite.setTextureRect(sf::IntRect(96*int(frame), 0, 96, 96));
        if(hit and hitTimer > hitCooldown){
            speed = 0;
            hitframe += 0.009f * time;
            if (hitframe > 4) {
                hitframe -= 4;
                hit = false;
                hitTimer = 0;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(hitframe), 576, 96, 96));
        }
        /*if(isOnGround and (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
            crawling = true;
            while (crawlFrame < 5){
                crawlFrame += 0.009f * time;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame), 288, 96, 96));
        }else if (crawling){
            crawlFrame += 0.05f * time;
            if(crawlFrame > 9) {
                crawling = false;
                crawlFrame -= 9;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame), 288, 96, 96));
        }*/
        crawlingAnim(time, dir, isOnGround);
    }
}

auto Character::setPosition(float x, float y) -> void {
    sprite.setPosition(x, y);
    this->x = x;
    this->y = y;
    grdlevel = y;
}

auto Character::crawlingAnim(float time, int dir, bool isOnGround) -> void {
    if(isOnGround and (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
        speed = speed/2;
        if(crawlFrame < 5){
            crawlFrame += 0.05f * time;

            crawling = true;
        }
        if(dir == 0) sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame), 288, 96, 96));
        else if(dir == 1) sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame) + 96, 288, -96, 96));
    }else if (crawling){
        crawlFrame += 0.05f * time;
        if(crawlFrame > 9) {
            crawling = false;
            crawlFrame -= 9;
        }
        if(dir == 0) sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame), 288, 96, 96));
        else if(dir == 1) sprite.setTextureRect(sf::IntRect(96 * int(crawlFrame) + 96, 288, -96, 96));
    }
}


