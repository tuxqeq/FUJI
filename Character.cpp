#include "Character.h"
#include "Level.h"
#include <fmt/core.h>
//TODO create animation class and handle animations there
Character::Character(float x, float y, float w, float h, std::string name, bool inGame)
        : x(x), y(y), w(w), h(h), name(name), inGame(inGame){
    image.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Character/" + name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    //sprite.setColor(sf::Color::Black);
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
    //sprite.setScale(0.66, 0.66);
    sprite.setPosition(x, y);
    jumpH = 0;
    grdlevel = y;
    heart.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Character/humanheart.png");
    hearts = std::vector<sf::Sprite>(5, sf::Sprite(heart));
    for (int i = 0; i < 5; i++){
        hearts[i].setTextureRect(sf::IntRect(0, 0, 64, 64));
        hearts[i].setScale(0.75, 0.75);
    }
}
bool jumping = false;
bool hit = false;
bool crawling = false;
bool isOnGround = false;
auto Character::update(float time, sf::Vector2u vector2, sf::RenderWindow* wnd) -> void {
    if(not inGame) sprite.setScale(0.75, 0.75);
    //else sprite.setScale(sf::Vector2f(0.5f, 0.5f));
    x += speed*time;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) and not jumping){
        hit = true;
    }
    if(inGame) {
        collisionX(0);
    }

    y += speedY*time;
    if(inGame) {
        collisionX(1);
    }
    //isOnGround = false;
    jumpH -= speedY*time;
    bool ableToJump = false;
    sprite.setPosition(x - offsetX, y-offsetY - 72);
    if(inGame and x > 200) offsetX = x - 200;
    //TODO offsetY
    //if(y < 400) offsetY = y - 400;
    speed = 0;
    jumpTimer += time;
    hitTimer += time;
    if (x > vector2.x and not inGame){
        x = -45;
    }
    if(x < -45 and not inGame){
        x = vector2.x;
    }
    if(jumping or not isOnGround){
        isOnGround = false;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) speedY += 0.025f*time;
        speedY += 0.005f*time;
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

    if(not inGame and jumpH <= 0){
        speedY = 0;
        //y = grdlevel;
        isOnGround = true;
        jumping = false;
    }
    if(isOnGround and jumpTimer > jumpCooldown){
        ableToJump = true;
    }

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        and ableToJump
        and not crawling){
        speedY = -1;
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
            hitframe += 0.02f * time;
            if (hitframe > 4) {
                hitframe -= 4;
                hit = false;
                hitTimer = 0;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(hitframe)+96, 576, -96, 96));
        }
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
            hitframe += 0.02f * time;
            if (hitframe > 4) {
                hitframe -= 4;
                hit = false;
                hitTimer = 0;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(hitframe), 576, 96, 96));
        }
        crawlingAnim(time, dir, isOnGround);
    }else if(not jumping){
        frame += 0.009f * time;
        if(frame > 6) frame -= 6;
        if(dir == 1) sprite.setTextureRect(sf::IntRect(96*int(frame) + 96, 0, -96, 96));
        else sprite.setTextureRect(sf::IntRect(96*int(frame), 0, 96, 96));
        if(hit and hitTimer > hitCooldown){
            speed = 0;
            hitframe += 0.02f * time;
            if (hitframe > 4) {
                hitframe -= 4;
                hit = false;
                hitTimer = 0;
            }
            sprite.setTextureRect(sf::IntRect(96 * int(hitframe), 576, 96, 96));
        }
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
auto Character::collisionX(int num) -> void {
    for (int k = x/48; k < (x + 48)/48; k++){
        if(Level::levels[int(y + 48)/48][k] == ' ' or Level::levels[int(y + 48)/48][k] == 's'){
            if(speedY == 0 and num == 1){
                isOnGround = false;
            }
        }
        if(k > x/48 and k < (x + 48)/48) {
            if (Level::levels[int(y + 24) / 48][k] == 's') {
                health -= 1;
                offsetX = 0;
                x = 75;
                y = 720;
                minusheart = true;
            }
        }
    }
    for (int i = y/48; i < (y + 48)/48; i++) {
        for (int j = (x + 24)/48; j < (x + 48)/48; j++) {
            if(Level::levels[i][j] == '0'
            or Level::levels[i][j] == 'd'
            or Level::levels[i][j] == 'C'
            //or Level::levels[i][j] == 's'
            or Level::levels[i][j] == 'b'
            or Level::levels[i][j] == 'w'){
                if(speedY > 0 and num == 1) {
                    isOnGround = true;
                    speedY = 0;
                    fmt::print("{}\n", i);
                    jumping = false;
                    y = i*48 - 48;
                    fmt::print("{}\n", y);

                    //jumpH = 0;
                }
                if (speedY < 0 and num == 1) {
                    y = i * 48 + 48;
                }
                if(speed > 0 and num == 0) {
                    if(hit){
                        Level::levels[i][j] = ' ';
                    }
                    x = j*48 - 48;
                }
                if(speed < 0 and num == 0) {
                    if(hit){
                        Level::levels[i][j] = ' ';
                    }
                    x = j*48 + 24;
                }
            }
        }
    }
}

auto Character::getXY() -> std::pair<float, float>{
    return std::make_pair(offsetX, offsetY);
}

auto Character::drawhealth(sf::RenderWindow* wnd) -> void {
    for (int i = 0; i < health; ++i) {
        hearts[i].setPosition(i * 48, 0);
        wnd->draw(hearts[i]);
    }
}


