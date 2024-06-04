#include "Level.h"


Level::Level(Character* character) : character(character){
    //shape = sf::RectangleShape(sf::Vector2f(48, 48));
    background = new Background("level1.png");
    texture.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Level/nicefloor.png");
    shape.setTexture(texture);
    spike.loadFromFile("/Users/tuxqeq/Documents/CLion/Project.cpp/assets/Level/spike.png");
}

std::vector</*std::vector<*/std::string> Level::levels = {
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "w                            d                                                                                                                       w",
        "w                            d                                                                                                                       w",
        "w                            d                                                                                                                       w",
        "w                            d                                                                                                                       w",
        "w                            d                                                                                                                       w",
        "w                            d                                     w               kk                                                                w",
        "w                            d                                                      k  k         w                                                   w",
        "w                            d                                                      k      k  k                                                      w",
        "w              w                                                                   kkk   kkk  kkk                           w                        w",
        "w                                                       b                            k  k         k                           kk                     w",
        "w       c       c            b                         bb   bbbbbb   bb              kk     r   kk            g              k  k    d               w",
        "w                          b b                        bbb            bb                    rr                          d     k                       w",
        "w                           bb                       bbbb            bbb                 rrrr           G           g       k   kk                   w",
        "w          bbbbbbbbbbbb  b   b      bb              bbbbb            bbbb         c      rrrrr                       g     k     k    t0             w",
        "w       bssb                 b      bb             bbbbbbssssssssssssbbbbb       k k     rrrrrr      d              g   kk       k    00             w",
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
};

/*The "0" represents solid ground or boundaries.
The "s" s represents spikes
The "w" represents walls
The "c" represents coins or collectibles.
The "b" represents a kind of platform or block.
The "r" represents a rough terrain or something similar.
The "G" represents the goal or endpoint.*/

auto Level::draw(int level, sf::RenderWindow *wnd, std::pair<float, float> pair) -> void {
    background->setSize(wnd->getSize());
    wnd->draw(background->getBackground());
    for(int i=0; i < 17; i++){
        for (int j = 0; j < levels[i].size(); ++j) {
            shape.setTexture(texture);
            if(levels[i][j] == '0') {
                if(j == 0) shape.setTextureRect(sf::IntRect(0, 128, 32, 32));
                if(j == levels[i].size()-1) shape.setTextureRect(sf::IntRect(64, 128, 32, 32));
                else if (levels[i][j - 1] == '0' and levels[i][j + 1] == '0') shape.setTextureRect(sf::IntRect(32, 128, 32, 32));
                shape.setScale(1.5, 1.5);
            }
            if(levels[i][j] == 'd'){
                if (levels[i+1][j] != 'd'){
                    if (levels[i][j - 1] != 'd' and levels[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(0, 32, 32, -32));
                    if (levels[i][j - 1] == 'd' and levels[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(32, 32, 32, -32));
                    if (levels[i][j - 1] == 'd' and levels[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(64, 32, 32, -32));
                    if (levels[i][j - 1] != 'd' and levels[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(128, 32, 32, -32));
                }
                if(levels[i+1][j] == 'd') {
                    if (levels[i][j - 1] != 'd' and levels[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(128, 160, 32, 32));
                    if (levels[i][j - 1] == 'd' and levels[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(144, 160, 32, 32));
                    if (levels[i][j - 1] == 'd' and levels[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(160, 160, 32, 32));
                    if (levels[i][j - 1] != 'd' and levels[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(144, 160, 32, 32));
                }
            }
            if(levels[i][j] == 'b') {
                shape.setTextureRect(sf::IntRect(160, 32, 32, 32));

                //sides
                if (levels[i-1][j] != 'b' and levels[i+1][j] != 'b'){
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(160, 0, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(192, 0, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(224, 0, 32, 32));
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(288, 0, 32, 32));
                }
                if (levels[i-1][j] != 'b' and levels[i+1][j] == 'b'){
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(32, 0, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(64, 0, 32, 32));
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(128, 0, 32, 32));
                }
                //down
                if(levels[i-1][j] == 'b' and levels[i+1][j] == 'b') {
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(128, 160, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(144, 160, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(160, 160, 32, 32));
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(160, 160, 32, 32));
                }
                if(levels[i-1][j] == 'b' and levels[i+1][j] != 'b') {
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(256, 160, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(272, 160, 32, 32));
                    if (levels[i][j - 1] == 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(288, 160, 32, 32));
                    if (levels[i][j - 1] != 'b' and levels[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(272, 160, 32, 32));
                }
                //shape.setTextureRect(sf::IntRect(160, 32, 32, 32));
                if(levels[i-1][j] != 'b'
                   and levels[i+1][j] != 'b'
                   and levels[i][j+1] != 'b'
                   and levels[i][j-1] != 'b'
                        ){
                    shape.setTextureRect(sf::IntRect(160, 32, 32, 32));
                }
                shape.setScale(1.5, 1.5);
            }
            if(levels[i][j] == 'w') {
                shape.setTextureRect(sf::IntRect(360,240, 48, 48));
                shape.setScale(1.5, 1.5);
            }
            if(levels[i][j] == 'C') {
                shape.setTextureRect(sf::IntRect(360,240, 48, 48));
                shape.setScale(1.5, 1.5);
            }
            if(levels[i][j] == 's') {
                shape.setTexture(spike);
                shape.setTextureRect(sf::IntRect(0, 0, 48, 48));
                shape.setScale(1, 1);
            }
            if(levels[i][j] == ' ') continue;
            //shape.setScale(1.5, 1.5);
            shape.setPosition(j*48 - pair.first/* - wnd->getSize().x/2*/,
                              i*48 - pair.second - 48/* + wnd->getSize().y/1.5*/);
            wnd->draw(shape);
        }
    }
}

