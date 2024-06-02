#include "Level.h"


Level::Level(Character* character) : character(character){
    shape = sf::RectangleShape(sf::Vector2f(64, 64));
    background = new Background("level1.png");
}

std::vector</*std::vector<*/std::string> Level::levels = {

                "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
                "0                                                                                                                                                    0",
                "0                                                                                                                                                    0",
                "0                                                                                    w                                                               0",
                "0                   w                                  w                   w                                                                         0",
                "0                                      w                                       kk                                                                    0",
                "0                                                                             k  k    k    k                                                         0",
                "0                      c                                                      k      kkk  kkk  w                                                     0",
                "0                                                                       r     k       k    k                                                         0",
                "0                                                                      rr     k  k                                                                   0",
                "0                                                                     rrr      kk                                                                    0",
                "0               c    kckck                                           rrrr                                                                            0",
                "0                                      t0                           rrrrr                                                                            0",
                "0             0                        00              t0          rrrrrr            G                                                               0",
                "0      0      0  0       d             00              00         rrrrrrr                                                                            0",
                "0000000000000000000000000PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",

};

auto Level::draw(int level, sf::RenderWindow *wnd) -> void {
    background->setSize(wnd->getSize());
    wnd->draw(background->getBackground());
    for(int i=0; i < 16; i++){
        for (int j = 0; j < levels[i].size(); ++j) {
            if(levels[i][j] == 'P') shape.setFillColor(sf::Color::Magenta);
            if(levels[i][j] == ' ') continue;
            shape.setPosition(j*64 + 32, i*64);
            wnd->draw(shape);
        }
    }
}

 auto Level::collision(int num) -> void {
    for (int i = character->x/32; i < (character->x + character->w)/32; ++i) {
        for (int j = character->y/32; j < (character->y + character->h)/32; ++j) {
            if(levels[i][j] == '0'){
                if(character->speed > 0) character->x = j*32 - character->w;
                if(character->speed < 0) character->x = j*32 + 10;
            }
        }
    }
}
