//
// Created by mihav on 07.05.2025.
//

#include "Shop.h"

// cinstructors / inits/ sets

Shop::Shop() {}
Shop::~Shop() {
    delete(player);
    delete(window);
}

auto Shop::setPointers(
        sf::RenderWindow *window, Player *player
) -> void {
    this->window = window;
    this->player = player;

    this->initializations();
}

auto Shop::textSetter(
        sf::Text &text, const int &cSize, const sf::Color &color,
        const sf::Vector2f &pos, const std::string &content
) -> void {
    text.setFont(font);
    text.setCharacterSize(cSize);
    text.setFillColor(color);
    text.setPosition(pos);
    text.setString(content);
}

auto Shop::initializations() -> void {
    if(!font.loadFromFile("../dpcomic.ttf"))
        throw std::runtime_error("ERROR::GAMEFONT::While loading from file");

    this->windowSize = sf::Vector2f(window->getSize().x, window->getSize().y);

    initRegenerator();
    initBooster();
    initOneShotter();

    initExitText();
    initScoreText();
    initRgenerateText();
    initBoosterText();
    initOneShotterText();
}
auto Shop::initExitText() -> void {
    this->textSetter(
            exitText, 70, sf::Color::Green,
            {windowSize.x/2.25f, windowSize.y/7*6},
            std::string("Press 'M' to exit ")
    );
}

auto Shop::initScoreText() -> void {
    this->textSetter(
            scoreText, 70, sf::Color::Green,
            {windowSize.x/2.25f, windowSize.y/10},
            std::string("")
    );
}

auto Shop::initRgenerateText() -> void {
    this->textSetter(
        regenerateText, 60, sf::Color::White,
        {windowSize.x/4.3f, windowSize.y/2},
        std::string("Full HP recover\n(" +
                        std::to_string(regeneratorPrice)
                        +  "scorePoints)")
    );
}
auto Shop::initBoosterText() -> void {
    this->textSetter(
            speedBoosterText, 60, sf::Color::White,
            {windowSize.x/4.3f + windowSize.x/5, windowSize.y/2},
            std::string("Speed booster\n(" +
                        std::to_string(boosterPrice) + " scorePoints)")
    );
}
auto Shop::initOneShotterText() -> void {
    this->textSetter(
            oneShotterText, 60, sf::Color::White,
            {windowSize.x/4.3f + 2*windowSize.x/5, windowSize.y/2},
            std::string(
                    "One shotter\n[Kills anybody with one hit,\npress 'X' to shoot]\n("
                    + std::to_string(oneShotterPrice) + " scorePoints)")
    );
}

auto Shop::initRegenerator() -> void {
    if(!regeneratorTexture.loadFromFile("../heart.png.png"))
        throw std::runtime_error("ERROR::GAME::While loading health booster texture");

    regenerator.setTexture(regeneratorTexture);
    regenerator.setScale(12.f, 12.f);

    regenerator.setPosition(windowSize.x/4, windowSize.y/3);
    this->regeneratorPrice = 40;
}
auto Shop::initBooster() -> void {
    booster.setRadius(50);
    booster.setFillColor(sf::Color::Magenta);
    booster.setPosition(windowSize.x/4 + windowSize.x/4.5f, windowSize.y/2.8f);
    this->boosterPrice = 60;
}
auto Shop::initOneShotter() -> void {
    oneShotter.setRadius(100);
    oneShotter.setFillColor(sf::Color::Yellow);
    oneShotter.setPosition(windowSize.x/4 + 2*windowSize.x/4.5f, windowSize.y/2.8f);
    oneShotterPrice = 25;
}

// updates

auto Shop::update() -> void {
    updateScoreText();

    updateMousePos();
    updateRegenerator();
    updateBooster();
    updateOneShotter();
}

auto Shop::updateScoreText() -> void {
    scoreText.setString(
            "Your score points: " + std::to_string(player->playerPoints)
    );
}

auto Shop::updateRegenerator() -> void {
    if(
        regenerator.getGlobalBounds().contains(mousePos) && mouseClick()
        && player->playerPoints >= regeneratorPrice && player->playerHP < 50
    ) {
        player->playerHP = 50;
        player->playerPoints -= regeneratorPrice;
    }
}
auto Shop::updateBooster() -> void {
    if(
        booster.getGlobalBounds().contains(mousePos) && mouseClick()
        && player->playerPoints >= boosterPrice
    ) {
        player->playerVelocityX += 0.5f;
        player->playerVelocityY += 0.5f;
        player->playerPoints -= boosterPrice;
    }
}
auto Shop::updateOneShotter() -> void {
    if(
        oneShotter.getGlobalBounds().contains(mousePos) && mouseClick()
        && player->playerPoints >= oneShotterPrice
    ) {
        auto os = Player::Bullet({5, 5}, 100);
        os.setRadius(30);
        os.setFillColor(sf::Color::Red);
        player->oneShotters.push_back(os);

        player->playerPoints -= oneShotterPrice;
    }
}

auto Shop::updateMousePos() -> void {
    auto mousePoss = sf::Mouse::getPosition(*window);
    this->mousePos = {
            static_cast<float>(mousePoss.x),static_cast<float>(mousePoss.y)
    };
}
auto Shop::mouseClick() -> bool {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!mouseHeld)
        {
            this->mouseHeld = true;
        }
    } else
        this->mouseHeld = false;
    return mouseHeld;
}

// renders

auto Shop::renderExitText() -> void {
    window->draw(exitText);
}
auto Shop::renderScoreText() -> void {
    window->draw(scoreText);
}
auto Shop::renderRgenerateText() -> void {
    window->draw(regenerateText);
}
auto Shop::renderBoosterText() -> void {
    window->draw(speedBoosterText);
}
auto Shop::renderOneShotterText() -> void {
    window->draw(oneShotterText);
}

auto Shop::renderRegenerator() -> void {
    window->draw(regenerator);
}
auto Shop::renderBooster() -> void {
    window->draw(booster);
}
auto Shop::renderOneShotter() -> void {
    window->draw(oneShotter);
}

auto Shop::render() -> void {
    this->window->clear(sf::Color(137, 126, 180));

    renderExitText();
    renderScoreText();
    renderRgenerateText();
    renderBoosterText();
    renderOneShotterText();

    renderRegenerator();
    renderBooster();
    renderOneShotter();

    this->window->display();
}

// run

auto Shop::runShop() -> void {
    this->update();
    this->render();
}
