#pragma once
//
// Created by mihav on 28.05.2024.
//


#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <iterator>
#include <math.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Menu {
private:
    // variables

    sf::RenderWindow* menuWindow;
    sf::Event event;
    sf::Vector2f mousePos;
    sf::Clock* clock;

    // Texts

    sf::Font menuFont;

    sf::Text nameText;
    sf::Text startGameText;
    sf::Text savesText;
    sf::Text exitText;

    auto textSetter(
            sf::Text &text, const int &cSize, const sf::Color &color,
            const sf::Vector2f &pos, const std::string &content
    ) -> void;

    sf::Text victoryText;
    sf::Clock victoryClock;

    // Buttons

    sf::RectangleShape startButton;
    sf::RectangleShape savesButton;
    sf::RectangleShape exitButton;

    // Initialisations

    auto initMenuWindow() -> void;

    auto initVariabless() -> void;

    auto initMenuFont() -> void;

    auto initStartButton() -> void;
    auto initExitButtin() -> void;

    auto initNameText() -> void;
    auto initStartGameText() -> void;
    auto initSavesText() -> void;
    auto initExitText() -> void;

    auto initVictoryText() -> void;

public:

    // Constructors - destructors

    Menu();
    ~Menu();

    auto setWindow(sf::RenderWindow* menuWindow) -> void;
    auto setClock(sf::Clock* gClock) -> void;
    auto initialisations() -> void;

    // Flags

    bool gameStarted;
    bool won;


    const bool MenuisOpen() const;
    bool isGameStarted();

    auto whenWon() -> void;

    // Updates

    auto pollEvents() -> void;
    auto update() -> void;

    auto updateVictoryText() -> void;

    auto updateStartButton() -> void;
    auto updateExitButton() -> void;

    auto updateMousePos() -> void;

    // Renders

    auto render() -> void;

    auto renderNameText() -> void;
    auto renderStartGameText() -> void;
    auto renderSavesText() -> void;
    auto renderExitText() -> void;

    auto renderVictoryText() -> void;

    auto renderStartButton() -> void;
    auto renderExitButton() -> void;

    // Runner

    auto runMenu() -> void;
};
