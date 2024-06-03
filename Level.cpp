#include "Level.h"


Level::Level(Character* character) : character(character){
    //shape = sf::RectangleShape(sf::Vector2f(48, 48));
    background = new Background("level1.png");
    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Floor/nicefloor.png");
    shape.setTexture(texture);
}

std::vector</*std::vector<*/std::string> Level::levels = {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "w                            00                                                                                                                      w",
        "w                            00                                                                                                                      w",
        "w                            00                                                                                                                      w",
        "w                            00                                                                                                                      w",
        "w                            00                                    w               kk                                                                w",
        "w                            00                                                     k  k         w                                                   w",
        "w                            00                                                     k      k  k                                                      w",
        "w              w                                               kkk    r             kkk   kkk  kkk                           w                       w",
        "w                                                      r     kkkkk                  k  k         k                           kk                      w",
        "w       c       c            00                       rr     k  k     r              kk     r   kk            g              k  k    d               w",
        "w                          0 00                      rrr      k      rr                    rr                          d     k                       w",
        "w                           000                     rrrr             rrr                 rrrr           G           g       k   kk                   w",
        "w          000000000000  0   00     00              rrrrr            rrrr         c      rrrrr                       g     k     k    t0             w",
        "w       0ss0      c          00     00             rrrrrr            rrrrr       k k     rrrrrr      d              g   kk       k    00             w",
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
};

/*The "0" represents solid ground or boundaries.
The "s" s represents spikes
The "w" represents walls
The "k" represents a kind of platform or block.
The "r" represents a rough terrain or something similar.
The "t0" represents a trap or something hazardous.
The "c" represents coins or collectibles.
The "G" represents the goal or endpoint.
The "d" and "g" can represent other specific elements like doors and gates.*/

auto Level::draw(int level, sf::RenderWindow *wnd, std::pair<float, float> pair) -> void {
    background->setSize(wnd->getSize());
    wnd->draw(background->getBackground());
    for(int i=0; i < 16; i++){
        for (int j = 0; j < levels[i].size(); ++j) {
            if(levels[i][j] == '0') {
                shape.setTextureRect(sf::IntRect(96, 128, 32, 32));
                shape.setScale(1.5, 1.5);
            }
            if(levels[i][j] == 'w') shape.setTextureRect(sf::IntRect(360,240, 48, 48));
            //if(levels[i][j] == 's') shape.setFillColor(sf::Color::Black);
            if(levels[i][j] == ' ') continue;
            shape.setPosition(j*48 - pair.first/* - wnd->getSize().x/2*/,
                              i*48 - pair.second/* + wnd->getSize().y/1.5*/);
            wnd->draw(shape);
        }
    }
}

