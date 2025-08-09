//
// Created by mihav on 07.05.2025.
//
#pragma once



#include "Player.h"
struct Shop {

// object variables

    Player* player;

    sf::RenderWindow* window;
    sf::Vector2f windowSize;

    sf::Event event;
    sf::Vector2f mousePos;

// texts

    sf::Font font;
    sf::Text exitText;
    sf::Text scoreText;
    sf::Text speedBoosterText;
    sf::Text oneShotterText;
    sf::Text regenerateText;

// items

    sf::CircleShape oneShotter;
    sf::CircleShape booster;
    sf::Sprite regenerator;
    sf::Texture regeneratorTexture;

    //their prices

    int oneShotterPrice;
    int boosterPrice;
    int regeneratorPrice;

// flags

    bool mouseHeld;

// setters / inits / constructors

    Shop();
    ~Shop();
    auto setPointers(sf::RenderWindow* window, Player* player) -> void;

    auto textSetter(
            sf::Text &text, const int &cSize, const sf::Color &color,
            const sf::Vector2f &pos, const std::string &content
    ) -> void;

    auto initializations() -> void;

    auto initExitText() -> void;
    auto initScoreText() -> void;
    auto initBoosterText() -> void;
    auto initOneShotterText() -> void;
    auto initRgenerateText() -> void;

    auto initOneShotter() -> void;
    auto initBooster() -> void;
    auto initRegenerator() -> void;

// updates

    auto update() -> void;
    auto pollEvents() -> void;

    auto updateOneShotter() -> void;
    auto updateBooster() -> void;
    auto updateRegenerator() -> void;
    auto updateMousePos() -> void;

    auto mouseClick() -> bool;

    auto updateScoreText() -> void;

// renders

    auto render() -> void;

    auto renderExitText() -> void;
    auto renderScoreText() -> void;
    auto renderBoosterText() -> void;
    auto renderOneShotterText() -> void;
    auto renderRgenerateText() -> void;

    auto renderRegenerator() -> void;
    auto renderBooster() -> void;
    auto renderOneShotter() -> void;

// run

    auto runShop() -> void;
};


