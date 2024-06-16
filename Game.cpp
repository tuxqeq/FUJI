#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game", sf::Style::Titlebar | sf::Style::Close);
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
    background = new Background("fudzimenu.png");

    newGame = new Button(250, 225, 120, 30, 720, 180, "newgame.png");
    continueGame = new Button(420, 225, 120, 30, 720, 180, "continue.png");
    nextLevel = new Button(130, 200, 120, 30, 720, 180, "nextlevel.png");
    goToMainMenu = new Button(300, 200, 120, 30, 720, 180, "mainmenu.png");
    restart = new Button(1550, 10, 32, 32, 320, 320, "restart.png");
    restart2 = new Button(200, 200, 32, 32, 320, 320, "restart.png");

    currentLevel = 0;
    readsave();

    font.loadFromFile("../assets/Font/pixel.ttf");
    text = sf::Text("Coins collected", font, 14);
    text.setFillColor(sf::Color::Black);
    text.setLetterSpacing(0.02);
    text.setOutlineThickness(0.3);
    text.setOutlineColor(sf::Color(255, 32, 161, 255));
    text.setPosition(window->getSize().x - 250, 40);

    whatlevel = sf::Text("you are on level:", font, 14);
    whatlevel.setFillColor(sf::Color::White);
    whatlevel.setLetterSpacing(0.02);
    whatlevel.setOutlineThickness(0.3);
    whatlevel.setOutlineColor(sf::Color(255, 32, 161, 255));
    whatlevel.setPosition(410, 270);

    infoText = sf::Text("you are on level:", font, 14);
    infoText.setFillColor(sf::Color::White);
    infoText.setLetterSpacing(0.02);
    infoText.setOutlineThickness(0.3);
    infoText.setOutlineColor(sf::Color(255, 32, 161, 255));
    infoText.setPosition(30, 470);
}

Game::~Game(){
    delete this->window;
}

bool Game::running() const {
    return window->isOpen();
}

auto Game::pollEvents() {
    while (window->pollEvent(event)){
        switch (event.type) {
            case sf::Event::Closed:
                writeData();
                window->close();
                break;
            case sf::Event::MouseButtonPressed:{
                if(restart->isPressed(window)){
                    newLevel(currentLevel);
                }
                if(restart2->isPressed(window)){
                    newLevel(currentLevel);
                }
                if(goToMainMenu->isPressed(window)){
                    mainmenu();
                }
                if(nextLevel->isPressed(window)){
                    newLevel(currentLevel);
                }


                if(newGame->isPressed(window)){
                    newLevel(0);
                    currentLevel= 0;
                }
                if(continueGame->isPressed(window)){
                    newLevel(currentLevel);
                }
            }
            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape) {
                    if(ingame or inmidlev){
                        mainmenu();
                    }
                    else {
                        window->close();
                        break;
                    }
                }
            }

        }
    }
}

auto Game::update(float time) -> void{
    if(ingame) {
        std::string textforDispl = fmt::format("Coins collected: {}", character->coinsCollected);
        text.setString(textforDispl);
    }if(not ingame){
        std::string textforDispl = fmt::format("Coins collected: {}", CollectedCoins);
        text.setString(textforDispl);
    }
    if(not ingame and not inmidlev and not inlevFailed){
        std::string levelnum = fmt::format("You are on level: {} ", currentLevel+1);
        whatlevel.setString(levelnum);
        std::string info = fmt::format("Moving is A(left), S(crawl), D(right), Space(jump/uncrawl) and arrows."
                                       "\n\nBy pressing R you can hit enemies and break blocks creating caves."
                                       "\n\nEvery coin you collect can speed up you, hit you and heal you(Chances are random)");
        infoText.setString(info);
    }
    pollEvents();
    background->setSize(window->getSize());
    if(character->minusheart) restartLevel();
    if(character->end) {
        levelEnd();
        currentLevel += 1;
    }
    if(character->health == 0) levelfailed();
    else character->update(time, window->getSize(), this->window);
    if(ingame) {
        character->clevel->updateEnemies(time);
        character->clevel->updateCoins(time);
    }
}

auto Game::render() -> void{
    window->clear();
    window->draw(background->getBackground());
    if(not ingame and not inmidlev and not inlevFailed) {
        window->draw(newGame->shape);
        window->draw(continueGame->shape);
        window->draw(whatlevel);
        window->draw(infoText);
    }
    else if(inmidlev){
        window->draw(nextLevel->shape);
        window->draw(goToMainMenu->shape);
    }
    else if(inlevFailed){
        window->draw(restart2->shape);
        window->draw(goToMainMenu->shape);
    }
    else if(ingame) {
        level->draw(this->window, this->character->getOffsetXY());
        character->drawhealth(this->window);
        character->clevel->drawEnemies(window);
        character->clevel->drawCoins(window);
        window->draw(restart->shape);
    }
    window->draw(character->sprite);
    text.setPosition(window->getSize().x - 200, 50);
    window->draw(text);

    window->display();
}

auto Game::mainmenu() -> void {
    background = new Background("fudzimenu.png");
    inmidlev =  false;
    inlevFailed =  false;
    ingame = false;
    window->close();
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "game",
                                  sf::Style::Titlebar | sf::Style::Close);
    delete character;
    character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
}

auto Game::restartLevel() -> void {
    character->setPosition(75, window->getSize().y - 96);
    character->offsetX = 0;
    character->inGame = true;
    character->minusheart = false;
    character->speedupTimer = 2000;
}



auto Game::levelEnd() -> void {
    CollectedCoins += character->coinsCollected;
    background = new Background("midlev.png");
    ingame = false;
    inmidlev = true;
    character->inGame = false;
    character->end = false;
    window->close();
    window = new sf::RenderWindow(sf::VideoMode(600, 400), "game",
                                  sf::Style::Titlebar | sf::Style::Close);
    character->setPosition(10000, 10000);

}

auto Game::newLevel(int num) -> void {
        inmidlev = false;
        inlevFailed = false;
        ingame = true;
        window->close();
        level = new Level(num);
        window = new sf::RenderWindow(sf::VideoMode(1600, 768), "GameStarted",
                                      sf::Style::Titlebar | sf::Style::Close);
        delete character;
        character = new Character(75, window->getSize().y - 150, 96, 96, "ninja.png", false);
        character->inGame = true;
        character->clevel = level;
}

auto Game::levelfailed() -> void {
    background = new Background("levfailed.png");
    ingame = false;
    inlevFailed = true;
    character->inGame = false;
    //character->saveScore();
    character->health += 1;
    window->close();
    window = new sf::RenderWindow(sf::VideoMode(600, 400), "game",
                                  sf::Style::Titlebar | sf::Style::Close);
    character->setPosition(10000, 10000);
}

auto Game::readsave() -> void {
    std::string filePath = "../saving/save.txt";
    std::ifstream infile(filePath);
    if (infile.good()) {
        int intValue1, intValue2;

        infile >> currentLevel;
        infile >> CollectedCoins;

        infile.close();
    }else {
        std::ofstream outfile(filePath);
        if (outfile.is_open()) {
            currentLevel = 0;
            CollectedCoins = 0;
            outfile << currentLevel << "\n" << CollectedCoins << "\n";
            outfile.close();
        }
    }
}

auto Game::writeData() -> void {
    std::string filePath = "../saving/save.txt";
    std::ofstream outfile(filePath);
    if (outfile.is_open()) {
        outfile << currentLevel << "\n" << CollectedCoins << "\n";
        outfile.close();
    } else {
        std::cerr << "Error opening the file '" << filePath << "' for writing.\n";
    }
}
