#include "Level.h"


std::vector<std::vector<std::string>> Level::levels = {
        {
                "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
                "w                            d                                                          cE                                                           w",
                "w                            d                                                       c                            cc    E                           Ew",
                "w                            d                                                       b   ssssssss            cc   bbssss                    c   c    w",
                "w                            d                                                c  cc c    bbbbbbbb       cc   bb     bbbb                c c e c e c Ew",
                "w                        E  Ed                                                bbbbbbb                   bb                           c  C C C C C C Cw",
                "w                            d                                            ssss       cccceccccccp   c                       cc    c  bsssssssssssssssw",
                "w                            d                                            bbbb       bbbbbbbbbbbbb  b                       CC    CCCCCCCCCCCCCCCCCCCw",
                "w                           dd                                                                                          bb      b                    w",
                "w      ss    pss    pebsc                               e                                              b cccc ss  ccccbssssssssssssssssssssssssssssssw",
                "w      bbbbbbbbbbbbbbbbbbb                              b      c p                              c   bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbw",
                "w                            b                        cbb   bbbbbb   bc                             b               b                c               w",
                "w                          b b                       cbbb            bbc                          bbb    cccccccc   b           c    b              Ew",
                "w             c    p     c   b                      cbbbb            bbbc                         b     bbbbbbbbbb          cc  b    b              Ew",
                "w          bbbbbbbbbbbb  b   b      bb     cc      cbbbbb            bbbb    ccc  s              bb                         bb      bbb e   cc   c  Ew",
                "w   e c bssbqqQQQqqQQQqc e esbssseesbbscc sc css   bbbbbbssssssssssssbbbbb    pcccbccs  ssbsc   bbbsssssssssssssssssbbssbbsbssssssbbbbbbbsssbbsssbbbEw",
                "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        },
        {
                "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
                "w                                                                                                                    E                               w",
                "w                CC                                    C                                                                             cc              w",
                "w                     CC           C                                                                              cc                 CC              w",
                "w         CC                                                                                                 sssssbb cc     CC                   E   w",
                "w                              C           C                               C                                 bbbbb   bb cc        CC                 w",
                "w                CC                   C                                                                                 bb cc                        w",
                "w                                                                                                                          bb cc                     w",
                "w                                                                                                                        cc   bb cc                  w",
                "w                                                                                                                        CC      bb cc               w",
                "w                                                                                                                                   bb cc            w",
                "w                                                                                      cec                                             bb cc         w",
                "w          e                                          e                                bbb                                                bb         w",
                "w          b  b                                      bbbbsse      p sbbb             bsssssb      ss     p      p  ese    p                       p  w",
                "w          bc b c                                   bbbbbbbbbbbbbbbbbbbbb          bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb ccc bbbbbbbb w",
                "w   e    sbbbbbbbss        e    p     e       p    bbbbbbQQQQQQQQQQQbbbbbb       e QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQssQQQQQQQQQQw",
                "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        },
        {
                "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
                "w                                                                                ccc                                                              E  w",
                "w   c                                                                         CCCCCC                          ss   ss    ss         CCCCCCCCCCCCCCC  w",
                "w    c                                                                      C                             CCCCCCCCCCCCCCCCCCC  CCCC                 Ew",
                "w    b   bbb  cc C              c                                         C                                                                         Ew",
                "w    bb    b  CC    C         c C   ss                                CCC                  C             C                                          Ew",
                "w    b     b           C  ccc C    CCCC                            CC                     p    C       p                     c c c c ccc c c c c c   w",
                "w    b   bbb              CCC            C  C  C  C  C  C  C  C  C                    CCCCC        CCCCCC                    C C C C CCC C C C C C C w",
                "w    b     bsssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssw",
                "w    bb    bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbw",
                "w    b     b                                                                                                                ccc                      w",
                "w    b    bb                                                                                                                   p                     w",
                "w    bb                           b                                                         eee  e                       bbbbbbbbb                   w",
                "w    b                            sssbbbbbssb ss  ss   bssbbbbssb   ccccccccccccpccccccccccsbbbssb      p   eee    bssbssbcccccccbsee         p ss   w",
                "w    bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb    cbbbbbbbbbbbbbbbb cc bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb c bbbbbbbbbbbbbbbbbbbbbbbbbbb       bbbbbbbbbbbbbbbbbbb w",
                "w  e QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ c  pQQQQQQQQQQQQQQQQ ss QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ e QQQQQQQQQQQQQQQQQQQQQQQQQQQcebssbeQQQQQQQQQQQQQQQQQQQ w",
                "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        }
};


Level::Level(int num) : num(num){
    background = new Background("level1.png");
    texture.loadFromFile("../assets/Level/nicefloor.png");
    shape.setTexture(texture);
    spike.loadFromFile("../assets/Level/spike.png");
    cloud.loadFromFile("../assets/Level/clouds.png");
    curlevel = levels[num];
    numOfEnemy = 0;
    numOfCoin = 0;
    enemies = std::vector<Enemy*> {
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2),new Enemy("slime.png", 0, 10000, 10000, 2),
        new Enemy("slime.png", 0, 10000, 10000, 2)
    };

    coins = std::vector<Collectables*> {
        new Collectables(), new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
        new Collectables(),new Collectables(), new Collectables(), new Collectables(),
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
                shape.setScale(1.5, 1.5);
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
                shape.setScale(1.5, 1.5);
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
                shape.setTexture(cloud);
                shape.setTextureRect(sf::IntRect(0,0, 34, 34));
                shape.setScale(1.5, 1.5);
            }
            if(curlevel[i][j] == 's') {
                shape.setTexture(spike);
                shape.setTextureRect(sf::IntRect(0, 0, 48, 48));
                shape.setScale(1, 1);
            }
            if(curlevel[i][j] == ' ' or curlevel[i][j] == 'E') continue;
            shape.setPosition(j*48 - pair.first,
                              i*48 - pair.second - 48);
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




