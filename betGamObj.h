#pragma once


#include "Menu.h"
#include "Shop.h"
#include "Player.h"

#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <iterator>
#include <math.h>
#include <map>
#include <unordered_map>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


template <typename T>
concept boundable = requires(const T& t) {
    t.getGlobalBounds();
};

class betGamObj {

public:
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Clock clock;
    sf::Time timer;


    // Flags

    bool isGameInitialized;

    bool is2ndlvlInitialized;
    bool is3rdlvlInitialized;
    bool is4thLvlInitialized;
    bool isTrLvlInitialized;
    bool isLarLvlInitialized;

    bool isShopInitialized;
    bool isShopRunning;

    bool ifTimeScored;
    bool ifSbScored;
    bool ifHbScored;
    bool portalsActivated;

    bool enterHeld;
    bool xHeld;
    int lastMoveKeyPressed;


    enum class Level {
        first, second, third, tralalero, lirili, fourth
    };
    enum class PlayerAura {
        MID, COOK, BADDIE
    };

    Level lvl;
    PlayerAura aura;

    // Fonts / Texts

    sf::Font font;
    sf::Text levelText;
    sf::Text hpAndPointsText;
    sf::Text timerText;
    sf::Text coolness;
    sf::Text portalText;
    sf::Text shopText;
    sf::Text oneShottersText;

    sf::Text timeScore;
    sf::Clock timeScoreClock;

    sf::Text scoreBoosterText;
    sf::Clock sbClock;
    sf::Text healthBoosterText;
    sf::Clock hbClock;


    // Images / textures

    sf::Texture playerTexture;
    sf::Sprite playerImage;

    std::vector<sf::Sprite> scoreBoosters;
    std::vector<sf::Sprite> healthBoosters;
    sf::Texture sbTexture;
    sf::Texture hbTexture;

    auto setSbTexture() -> void;
    auto setHbTexture() -> void;

    // Locations

    Menu gMenu;
    Shop shop;


    // Player / Mobs

    Player player;

    auto loadPlayerTexture() -> void;

    //For mobs

    struct Mob : sf::Sprite {
        float mobVelocityX;
        float mobVelocityY;
        int mobHP;
        sf::Vector2f size;

        Mob(float VX, float VY, int hp)
        {
            this->mobVelocityX = VX;
            this->mobVelocityY = VY;
            this->mobHP = hp;
        }
    };

    sf::Texture lvl1Mob;
    sf::Texture lvl2Mob;
    sf::Texture lvl3Mob;
    sf::Texture lvl4Mob;


    auto loadMobsTextures() -> void;

    std::vector<Mob> mobs;
    std::vector<Mob> atackMobs;

    // bullets

    auto areMobsDead() -> bool;

    int bulletsMax;
    std::vector<Player::Bullet> bullets;


    //Objects

    sf::Texture type1Wall;
    sf::Texture type2Wall;
    auto loadWallTexture(
            sf::Texture& texture, const std::string& path
        ) -> void;

    struct Wall : sf::Sprite {
        sf::Vector2f size;
    };
    std::vector<Wall> walls;

    // Portal

    sf::RectangleShape portal1;
    sf::RectangleShape portal2;

    // Initialisations

    auto initWindow() -> void;
    auto initVariables() -> void;
    auto initPlayer() -> void;
    auto initMobs() -> void;
    auto initWalls() -> void;
    auto init1lvlHPBoosters() -> void;

    auto init2ndLvlWalls() -> void;
    auto init2ndLvlMobs() -> void;
    auto init2lvlHPBoosters() -> void;


    auto init3rdLvlWalls() -> void;
    auto init3rdLvlMobs() -> void;
    auto init3lvlHPBoosters() -> void;
    auto initPortals() -> void;

    auto initTrLvlWalls() -> void;
    auto initTrLvlMobs() -> void;
    auto initTrlvlHPBoosters() -> void;

    auto initLarLvlWalls() -> void;
    auto initLarLvlMobs() -> void;
    auto initLarlvlHPBoosters() -> void;

    auto init4thLvlWalls() -> void;
    auto init4thLvlMobs() -> void;
    auto init4thLvlHPBoosters() -> void;

    // init helpers
    auto hpBoosterSetter(
            const std::vector<sf::Vector2f>& hpPos, const std::vector<sf::Vector2f>& sbPos
            ) -> void;
    auto textSetter(
        sf::Text& text, const int& cSize, const sf::Color& color,
        const sf::Vector2f& pos, const std::string& content
            ) -> void;
    auto textSetter(
        sf::Text& text, const int& cSize, const sf::Color& color) -> void;
    auto wallSetter(
        const std::vector<std::pair<sf::Vector2f, sf::Vector2f>>& type1Walls,
        const std::vector<std::pair<sf::Vector2f, sf::Vector2f>>& type2Walls
            ) -> void;
    auto lvl1MobSetter(const std::vector<sf::Vector2f>& positions) -> void;
    auto lvl2MobSetter(const std::vector<sf::Vector2f>& positions) -> void;


//    auto initBullets() -> void;

    auto initFont() -> void;

    auto initLevelText() -> void;
    auto initHPText() -> void;
    auto initTimerText() -> void;
    auto initCoolnessText() -> void;
    auto initOneShottersText() -> void;

    auto initTimeScoreText() -> void;
    auto initSbText() -> void;
    auto initHbText() -> void;
    auto initPortalText() -> void;
    auto initShopText() -> void;

    //Creating

    auto createMob(
            float VX = 2.f, float VY = 2.f, int hp = 5,
            sf::Vector2f size = {50.f, 50.f},
            sf::Vector2f pos = {500.f, 500.f}, bool random = false
    ) -> void;

    auto createAtackMob(
            float VX = 2.f, float VY = 2.f, int hp = 5,
            sf::Vector2f size = {50.f, 50.f,},
            sf::Vector2f pos = {50.f, 50.f}
    ) -> void;

    auto createAdvAtackMob(
            float VX = 2.f, float VY = 2.f, int hp = 5,
            sf::Vector2f size = {50.f, 50.f,},
            sf::Vector2f pos = {50.f, 50.f}
    ) -> void;

    auto createBossMob(
            float VX = 2.f, float VY = 2.f, int hp = 5,
            sf::Vector2f size = {50.f, 50.f,},
            sf::Vector2f pos = {50.f, 50.f}
    ) -> void;

    auto createPlayer(
            float VX = 2.f, float VY = 2.f, int hp = 50,
            sf::Vector2f pos = {50, 50}
    ) -> void;

    auto createWall(
            sf::Vector2f size, sf::Vector2f pos, sf::Color color
    ) -> void;
    auto createWall(
            const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Texture& texture
    ) -> void;

    auto createHealthBooster(sf::Vector2f pos) -> void;
    auto createScoreBooster(sf::Vector2f pos) -> void;


    auto createBullet() -> void;
    auto shootOneShotter() -> void;
    auto bulletDirecting(Player::Bullet& bullet,
                         const sf::Vector2f& bulletSpeed
     ) -> void;

    // Interactions

    auto ifDamaged(const sf::Vector2f& origPos) -> void;


    template<boundable T>
    auto objWallInteraction(const T& obj) -> bool;

    auto circleIntersectsWMapEnd(const sf::CircleShape& circle) -> bool;

    auto avoidWalls(const Mob& attackMob, const sf::Vector2f& direction) -> sf::Vector2f;

    // Player / activity

    auto ifShooting() -> bool;



    sf::RenderWindow window;
    float windowSizeX;
    float windowSizeY;

    //Constructors / destructors

    betGamObj();

    virtual ~betGamObj();

    auto setFirstLevel() -> void;
    auto setSecondLevel() -> void;
    auto setThirdLevel() -> void;
    auto setTralaleroLevel() -> void;
    auto setLiriliLevel() -> void;
    auto setFourthLevel() -> void;

    auto unset() -> void;

    auto unsetWalls() -> void;
    auto unsetMobs() -> void;
    auto unsetHPBoosters() -> void;

    // Cheks

    auto getWindowisOpen() -> bool;
    auto intersectsWMob(const Player::Bullet& bullet)-> bool;

    auto timeScored(int score) -> void;
    auto sbScored(sf::Vector2f pos) -> void;
    auto hbScored(sf::Vector2f pos) -> void;


    // Updates

    auto pollEvents() -> void;
    auto updateShopPressed() -> void;
    auto updateMobs() -> void;
    auto updateAtackMobs() -> void;
    auto updatePlayer() -> void;
    auto updateAura() -> void;
    auto updateHPBoosters() -> void;

    auto updateLevelText() -> void;
    auto updateHPText() -> void;
    auto updateTimerText() -> void;
    auto updateCoolnessText() -> void;
    auto updateOneShottersText() -> void;

    auto updateTimeScoredText() -> void;
    auto updateSbText() -> void;
    auto updateHbText() -> void;

    auto update() -> void;
    auto updateBullets(std::vector<Player::Bullet>& bullets) -> void;

    //Renders

    auto render() -> void;
    auto render2ndLvlMobs() -> void;
    auto renderPlayer(sf::RenderTarget& target) -> void;
    auto renderWalls(sf::RenderTarget& target) -> void;
    auto renderBullets(const std::vector<Player::Bullet>& bulls) -> void;
    auto renderPortals(sf::RenderTarget& target) -> void;

    auto renderHPBoosters() -> void;;

    auto renderLevelText(sf::RenderTarget& target) -> void;
    auto renderHPText(sf::RenderTarget& target) -> void;
    auto renderTimerText() -> void;
    auto renderCoolnessText() -> void;
    auto renderPortalText() -> void;
    auto renderShopText() -> void;
    auto renderOneShottersText() -> void;

    auto renderTimeScoreText() -> void;
    auto renderSbText() -> void;
    auto renderHbText() -> void;

    // Runner

    auto run() -> void;
};


