//
// Created by mihav on 28.05.2024.
//

#include "Menu.h"

// initialisations

auto Menu::initVariabless() -> void
{
    this->gameStarted = false;
    this->won = false;
}


auto Menu::initMenuFont() -> void
{
    if (!this->menuFont.loadFromFile("../dpcomic.ttf"))
        throw std::runtime_error("ERROR::MENU::While loading the font");
}

    // texts

auto Menu::initNameText() -> void
{
    this->nameText.setFont(this->menuFont);
    this->nameText.setCharacterSize(150);
    this->nameText.setPosition(
            menuWindow->getSize().x / 2.75, menuWindow->getSize().y / 9.5
    );
    this->nameText.setString("Zaza kitteh");

    this->textSetter(
            nameText, 100, sf::Color::White,
            {menuWindow->getSize().x / 2.75f, menuWindow->getSize().y/9.5f},
            std::string("Zaza kitteh")
    );
}

auto Menu::initStartGameText() -> void
{
    this->textSetter(
            startGameText, 80, sf::Color::White,
            {menuWindow->getSize().x / 2.75f, menuWindow->getSize().y/6*2.f},
            std::string("Start new game")
    );
}

auto Menu::initSavesText() -> void
{
    this->textSetter(
            savesText, 80, sf::Color::White,
            {menuWindow->getSize().x / 2.75f, menuWindow->getSize().y/6*2.8f},
            std::string("Load a game")
    );
}

auto Menu::initExitText() -> void
{
    this->textSetter(
            exitText, 100, sf::Color::White,
            {menuWindow->getSize().x / 2.75f, menuWindow->getSize().y/6*4.f},
            std::string("Exit the game")
    );
}

auto Menu::initVictoryText() -> void
{
    this->textSetter(
        victoryText, 120, sf::Color::Green,
        {menuWindow->getSize().x/2.5f, menuWindow->getSize().y/4.5f},
        std::string("You Ate")
    );
}

auto Menu::textSetter(
        sf::Text &text, const int &cSize, const sf::Color &color,
        const sf::Vector2f &pos, const std::string &content
) -> void {
    text.setFont(menuFont);
    text.setCharacterSize(cSize);
    text.setFillColor(color);
    text.setPosition(pos);
    text.setString(content);
}

// Buttons

auto Menu::initStartButton() -> void
{
    this->startButton = sf::RectangleShape(
            sf::Vector2f(menuWindow->getSize().x / 3.8, menuWindow->getSize().y / 18)
    );
    startButton.setFillColor(
            sf::Color(128, 128, 128)
    );
    startButton.setPosition(
            startGameText.getPosition().x - menuWindow->getSize().x/85.333,
            startGameText.getPosition().y + menuWindow->getSize().y/55
    );
}

auto Menu::initExitButtin() -> void
{
    this->exitButton = sf::RectangleShape(
            sf::Vector2f(menuWindow->getSize().x / 3.05,
                   menuWindow->getSize().y / 10.5)
    );
    this->exitButton.setFillColor(
            sf::Color(128, 128, 128)
    );
    this->exitButton.setPosition(
        exitText.getPosition().x - menuWindow->getSize().x/85.33,
        exitText.getPosition().y + menuWindow->getSize().y/55
    );
}

// Constructors - destructors

auto Menu::setWindow(sf::RenderWindow* menuWindow) -> void
{
    this->menuWindow = menuWindow;
}

auto Menu::setClock(sf::Clock* gClock) -> void
{
    this->clock = gClock;
}

auto Menu::initialisations() -> void
{
    this->initVariabless();

    this->initMenuFont();

    this->initNameText();
    this->initStartGameText();
    this->initSavesText();
    this->initExitText();
    this->initVictoryText();

    this->initStartButton();
    this->initExitButtin();
}


Menu::Menu() {}

Menu::~Menu()
{
    delete this->clock;
    delete this->menuWindow;
}

// Checks


auto Menu::isGameStarted() -> bool
{
    return this->gameStarted;
}

auto Menu::whenWon() -> void
{
    victoryClock.restart();
    won = true;
}

// Uodates

auto Menu::update() -> void
{
    this->pollEvents();

    this->updateVictoryText();
}

auto Menu::pollEvents() -> void
{
    while (this->menuWindow->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                this->menuWindow->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    this->menuWindow->close();
                break;
        }

        this->updateStartButton();
        this->updateExitButton();

    }
}

auto Menu::updateVictoryText() -> void
{
    if (
        this->won && victoryClock.getElapsedTime() > sf::seconds(3)
    )
        this->won = false;
}

auto Menu::updateMousePos() -> void
{
    auto mousePosI = sf::Mouse::getPosition(*menuWindow);
    this->mousePos = {
        static_cast<float>(mousePosI.x),static_cast<float>(mousePosI.y)
    };

}

auto Menu::updateStartButton() -> void
{
    this->updateMousePos();
    if (startButton.getGlobalBounds().contains(this->mousePos))
    {
        startButton.setFillColor(sf::Color(255, 192, 203));
        if (event.type == sf::Event::MouseButtonPressed)
        {
            this->clock->restart();
            this->gameStarted = true;
        }
    } else
        startButton.setFillColor(
                sf::Color(128, 128, 128)
        );
}

auto Menu::updateExitButton() -> void {
    this->updateMousePos();
    if (exitButton.getGlobalBounds().contains(this->mousePos))
    {
        exitButton.setFillColor(sf::Color(255, 192, 203));
        if (event.type == sf::Event::MouseButtonPressed)
        {
            this->menuWindow->close();
        }
    } else
        exitButton.setFillColor(
                sf::Color(128, 128, 128)
        );
}


// Renders


auto Menu::render() -> void
{
    this->menuWindow->clear();

    this->renderStartButton();
    this->renderExitButton();

    this->renderNameText();
    this->renderStartGameText();
    this->renderSavesText();
    this->renderExitText();

    this->renderVictoryText();

    this->menuWindow->display();
}

    // text renders

auto Menu::renderNameText() -> void
{
    this->menuWindow->draw(nameText);
}

auto Menu::renderStartGameText() -> void
{
    this->menuWindow->draw(this->startGameText);
}

auto Menu::renderSavesText() -> void {
    this->menuWindow->draw(this->savesText);
}

auto Menu::renderExitText() -> void {
    this->menuWindow->draw(this->exitText);
}

auto Menu::renderVictoryText() -> void
{
    if (this->won)
        this->menuWindow->draw(this->victoryText);
}

    // buttons render

auto Menu::renderStartButton() -> void
{
    this->menuWindow->draw(startButton);
}

auto Menu::renderExitButton() -> void
{
    this->menuWindow->draw(exitButton);
}

// Runner

auto Menu::runMenu() -> void
{
    this->update();
    this->render();

}