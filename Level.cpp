#include "Level.h"


std::vector<std::vector<std::string>> Level::levels = {
        {
                "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                     w               kk                                                                w",
                "w                            d                                                      k  k         w                                                   w",
                "w                        E   d                                                      k      k  k                                                      w",
                "w                                                                               E   kkk   kkk  kkk                           w                       w",
                "w                        b                              b        p              E     k  k         k                           kk                    w",
                "w                            b                         bb   bbbbbb   b          E    kk     r   kk            g              k  k    d               w",
                "w                          b b                        bbb            bb         E           rr                          d     k                      w",
                "w             c    p     c   b                       bbbb            bbb        E         rrrr           G           g       k   kk                  w",
                "w          bbbbbbbbbbbb  b   b      bb              bbbbb            bbbb       E c      rrrrr                       g     k     k    t0             w",
                "w   e c bssbqqQQQqqQQQqc e esbssseesbbc      c     bbbbbbssssssssssssbbbbb      E k k     rrrrrr      d              g   kk       k    00            w",
                "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        },
        {
                "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                     w               kk                                                                w",
                "w                            d                                                      k  k         w                                                   w",
                "w                        E   d                                                      k      k  k                                                      w",
                "w                                                                               E   kkk   kkk  kkk                           w                       w",
                "w                        b                              b        p              E     k  k         k                           kk                    w",
                "w                            b                         bb   bbbbbb   b          E    kk     r   kk            g              k  k    d               w",
                "w          e               b b                        bbb            bb         E           rr                          d     k                      w",
                "w          b  b              b                       bbbb            bbb        E         rrrr           G           g       k   kk                  w",
                "w          bc b c        b   b      bb              bbbbb            bbbb       E c      rrrrr                       g     k     k    t0             w",
                "w   e    sbbbbbbbss    p e esbssseesbb             bbbbbbssssssssssssbbbbb      E k k     rrrrrr      d              g   kk       k    00            w",
                "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        },
        {
                "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                                                                                                       w",
                "w                            d                                     w               kk                                                                w",
                "w                            d                                                      k  k         w                                                   w",
                "w                        E   d                                                      k      k  k                                                      w",
                "w                                                                               E   kkk   kkk  kkk                           w                       w",
                "w                        b                              b                       E     k  k         k                           kk                    w",
                "w                            b                         bb   bbbbbb   b          E    kk     r   kk            g              k  k    d               w",
                "w          e               b b                        bbb            bb         E           rr                          d     k                      w",
                "w          b  b              b                       bbbb            bbb                  rrrr           G           g       k   kk                  w",
                "w          bc b c        b   b      bb              bbbbb            bbbb         c      rrrrr                       g     k     k    t0             w",
                "w                                                  bbbbbbssssssssssssbbbbb        k k     rrrrrr      d              g   kk       k    00            w",
                "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        }
};


/*The "0" represents solid ground or boundaries.
The "s" s represents spikes
The "w" represents walls
The "c" represents coins or collectibles.
The "b" represents a kind of platform or block.
The "r" represents a rough terrain or something similar.
The "G" represents the goal or endpoint.*/

Level::Level(int num) : num(num){
    //shape = sf::RectangleShape(sf::Vector2f(48, 48));
    background = new Background("level1.png");
    texture.loadFromFile("../assets/Level/nicefloor.png");
    shape.setTexture(texture);
    spike.loadFromFile("../assets/Level/spike.png");
    curlevel = levels[num];
    //enemy = new Enemy("slime.png", 0, 500, 500, 1);
    numOfEnemy = 0;
    numOfCoin = 0;
    enemies = std::vector<Enemy*> {
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2)
    };

    coins = std::vector<Collectables*> {
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
        new Collectables(),
    };
    coinsInCave = coins.size() - 1;
}




auto Level::draw(sf::RenderWindow *wnd, std::pair<float, float> pair) -> void {
    //curlevel = levels[1];
    background->setSize(wnd->getSize());
    wnd->draw(background->getBackground());
    for(int i=0; i < 17; i++){
        for (int j = 0; j < curlevel[i].size(); ++j) {
            shape.setTexture(texture);
            if(curlevel[i][j] == '0') {
                if(j == 0) shape.setTextureRect(sf::IntRect(0, 128, 32, 32));
                if(j == curlevel[i].size() - 1) shape.setTextureRect(sf::IntRect(64, 128, 32, 32));
                else if (curlevel[i][j - 1] == '0' and curlevel[i][j + 1] == '0') shape.setTextureRect(sf::IntRect(32, 128, 32, 32));
                shape.setScale(1.5, 1.5);
            }
            if(curlevel[i][j] == 'd'){
                if (curlevel[i + 1][j] != 'd'){
                    if (curlevel[i][j - 1] != 'd' and curlevel[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(0, 32, 32, -32));
                    if (curlevel[i][j - 1] == 'd' and curlevel[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(32, 32, 32, -32));
                    if (curlevel[i][j - 1] == 'd' and curlevel[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(64, 32, 32, -32));
                    if (curlevel[i][j - 1] != 'd' and curlevel[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(128, 32, 32, -32));
                }
                if(curlevel[i + 1][j] == 'd') {
                    if (curlevel[i][j - 1] != 'd' and curlevel[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(128, 160, 32, 32));
                    if (curlevel[i][j - 1] == 'd' and curlevel[i][j + 1] == 'd')
                        shape.setTextureRect(sf::IntRect(144, 160, 32, 32));
                    if (curlevel[i][j - 1] == 'd' and curlevel[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(160, 160, 32, 32));
                    if (curlevel[i][j - 1] != 'd' and curlevel[i][j + 1] != 'd')
                        shape.setTextureRect(sf::IntRect(144, 160, 32, 32));
                }
            }
            if(curlevel[i][j] == 'b') {
                shape.setTextureRect(sf::IntRect(160, 32, 32, 32));

                //sides
                if (curlevel[i - 1][j] != 'b' and curlevel[i + 1][j] != 'b'){
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(160, 0, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(192, 0, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(224, 0, 32, 32));
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(288, 0, 32, 32));
                }
                if (curlevel[i - 1][j] != 'b' and curlevel[i + 1][j] == 'b'){
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(32, 0, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(64, 0, 32, 32));
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(128, 0, 32, 32));
                }
                //down
                if(curlevel[i - 1][j] == 'b' and curlevel[i + 1][j] == 'b') {
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(128, 160, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(144, 160, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(160, 160, 32, 32));
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(160, 160, 32, 32));
                }
                if(curlevel[i - 1][j] == 'b' and curlevel[i + 1][j] != 'b') {
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(256, 160, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] == 'b')
                        shape.setTextureRect(sf::IntRect(272, 160, 32, 32));
                    if (curlevel[i][j - 1] == 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(288, 160, 32, 32));
                    if (curlevel[i][j - 1] != 'b' and curlevel[i][j + 1] != 'b')
                        shape.setTextureRect(sf::IntRect(272, 160, 32, 32));
                }
                //shape.setTextureRect(sf::IntRect(160, 32, 32, 32));
                if(curlevel[i - 1][j] != 'b'
                   and curlevel[i + 1][j] != 'b'
                   and curlevel[i][j + 1] != 'b'
                   and curlevel[i][j - 1] != 'b'
                        ){
                    shape.setTextureRect(sf::IntRect(160, 32, 32, 32));
                }
                shape.setScale(1.5, 1.5);
            }
            if(curlevel[i][j] == 'q' and curlevel[i-1][j] != 'b'){
                curlevel[i][j] = ' ';
            }
            if(curlevel[i][j] == 'q') {
                if (curlevel[i][j - 1] != 'q' and curlevel[i][j + 1] == 'q')
                    shape.setTextureRect(sf::IntRect(224, 113, 32, 15));
                if (curlevel[i][j - 1] == 'q' and curlevel[i][j + 1] == 'q')
                    shape.setTextureRect(sf::IntRect(256, 113, 32, 15));
                if (curlevel[i][j - 1] == 'q' and curlevel[i][j + 1] != 'q')
                    shape.setTextureRect(sf::IntRect(288, 113, 32, 15));
                if (curlevel[i][j - 1] != 'q' and curlevel[i][j + 1] != 'q')
                    shape.setTextureRect(sf::IntRect(320, 113, 32, 15));
            }
            if(curlevel[i][j] == 'Q') {
                curlevel[i][j] = 'q';
                std::random_device rd2;
                int random2 = rd2() % 20;
                if(not coins[coinsInCave]->collected and random2 < 12 and coinsInCave > 15){
                    fmt::println("{}", coinsInCave);
                    coins[coinsInCave]->setPosition(j * 48, i * 48 - 32);
                    coins[coinsInCave]->setOffset(pair);
                    coinsInCave--;
                }
                if (curlevel[i][j - 1] != 'q' and curlevel[i][j + 1] == 'q')
                    shape.setTextureRect(sf::IntRect(224, 113, 32, 15));
                if (curlevel[i][j - 1] == 'q' and curlevel[i][j + 1] == 'q')
                    shape.setTextureRect(sf::IntRect(256, 113, 32, 15));
                if (curlevel[i][j - 1] == 'q' and curlevel[i][j + 1] != 'q')
                    shape.setTextureRect(sf::IntRect(288, 113, 32, 15));
                if (curlevel[i][j - 1] != 'q' and curlevel[i][j + 1] != 'q')
                    shape.setTextureRect(sf::IntRect(320, 113, 32, 15));
            }
            if(curlevel[i][j] == 'w') {
                shape.setTextureRect(sf::IntRect(360,240, 48, 48));
                shape.setScale(1.5, 1.5);
            }
            if(curlevel[i][j] == 'e'){
                curlevel[i][j] = ' ';
                std::random_device rd;
                int random = rd() % 10;
                if(enemies[numOfEnemy]->life and random < 9){
                    enemies[numOfEnemy]->setText("slime.png");
                    enemies[numOfEnemy]->setPosition(j * 48, i * 48 - 48);
                    enemies[numOfEnemy]->setOffset(pair);
                    numOfEnemy++;
                }
            }

            if(curlevel[i][j] == 'p'){
                curlevel[i][j] = ' ';
                std::random_device rd;
                int random = rd() % 10;
                if(enemies[numOfEnemy]->life and random < 9){
                    enemies[numOfEnemy]->health = 3;
                    enemies[numOfEnemy]->setText("slime_purple.png");
                    enemies[numOfEnemy]->speed = -0.2;
                    enemies[numOfEnemy]->setPosition(j * 48, i * 48 - 48);
                    enemies[numOfEnemy]->setOffset(pair);
                    numOfEnemy++;
                }
            }
            if(curlevel[i][j] == 'c'){
                curlevel[i][j] = ' ';
                std::random_device rd;
                int random = rd() % 10;
                if(not coins[numOfCoin]->collected and random < 8){
                    coins[numOfCoin]->setPosition(j * 48, i * 48 - 32);
                    coins[numOfCoin]->setOffset(pair);
                    numOfCoin++;
                }
            }
            if(curlevel[i][j] == 'C') {
                shape.setTextureRect(sf::IntRect(360,240, 48, 48));
                shape.setScale(1.5, 1.5);
            }
            if(curlevel[i][j] == 's') {
                shape.setTexture(spike);
                shape.setTextureRect(sf::IntRect(0, 0, 48, 48));
                shape.setScale(1, 1);
            }
            if(curlevel[i][j] == ' ') continue;
            //shape.setScale(1.5, 1.5);
            shape.setPosition(j*48 - pair.first/* - wnd->getSize().x/2*/,
                              i*48 - pair.second - 48/* + wnd->getSize().y/1.5*/);
            wnd->draw(shape);
        }
    }
    for (auto i : enemies){
        i->setOffset(pair);
    }
    for (auto i : coins){
        i->setOffset(pair);
    }
}

auto Level::updateEnemies(float time) -> void {
    for (auto i : enemies){
        i->update(time);
    }
}

auto Level::updateCoins(float time) -> void {
    for (auto i : coins){
        i->update(time);
    }
}

auto Level::drawEnemies(sf::RenderWindow *wnd) -> void {
    for (auto i : enemies){
        wnd->draw(i->sprite);
    }
}

auto Level::drawCoins(sf::RenderWindow *wnd) -> void {
    for (auto i : coins){
        wnd->draw(i->sprite);
    }
}

Level::~Level() {
    for (auto i : enemies){
        delete i;
    }
    for (auto j : coins){
        delete j;
    }
}




