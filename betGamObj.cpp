
#include "betGamObj.h"
#include "Menu.h"


//Initialisations

auto betGamObj::initVariables() -> void
{
    this->enterHeld = false;
    this->xHeld = false;

    this->ifTimeScored = false;
    this->ifSbScored = false;
    this->ifHbScored = false;
    this->portalsActivated = false;

    bool isShopInitialized = false;
    bool isShopRunning = false;

    this->bulletsMax = 10;
}


auto betGamObj::initWindow() -> void
{
    this->window.setFramerateLimit(240);
}

auto betGamObj::initPlayer() -> void
{
    this->createPlayer(
            2.f, 2.f, 50, {windowSizeX/51.2f, windowSizeY/32}
    );
}

auto betGamObj::initMobs() -> void
{
    this->loadMobsTextures();
    this->mobs = std::vector<Mob>();

    auto mobPositions = std::vector<sf::Vector2f>{
            sf::Vector2f(windowSizeX/5*4, windowSizeY/4*3),
            sf::Vector2f(windowSizeX/1.8, windowSizeY/3),
            sf::Vector2f(windowSizeX/1.7, windowSizeY/5*4),
            sf::Vector2f(windowSizeX/4*3, windowSizeY/4),
            sf::Vector2f(windowSizeX/4, windowSizeY/1.7)
    };
    this->lvl1MobSetter(mobPositions);
}

auto betGamObj::initWalls() -> void
{
    this->loadWallTexture(type1Wall, "../type1Wall.png");
    this->loadWallTexture(type2Wall, "../type2Wall.png");

    auto type11Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                {windowSizeX/7.5f, windowSizeY/25},
                {windowSizeX/1.52f, windowSizeY/1.42f}
            }, {
                {windowSizeX/26.6f, windowSizeY/4.8f},
                {windowSizeX/2.1f, windowSizeY/2.1f}
            }, {
                {windowSizeX / 26.6f, windowSizeY / 4.8f},
                {windowSizeX / 3, windowSizeY / 4*2.5f}
            }, {
                {windowSizeX / 26.6f, windowSizeY / 4},
                {windowSizeX / 6.7f, windowSizeY / 4*2.5f}
            }, {
                {windowSizeX/7.5f, windowSizeY/25},
                {windowSizeX/2, windowSizeY/4}
            }, {
                {windowSizeX/26.6f, windowSizeY/4.8f},
                {windowSizeX/5*4, windowSizeY/2.6f}
            }

    };

    this->wallSetter(type11Walls, {{
            {windowSizeX/4.8f, windowSizeY/26.6f}, {windowSizeX/6, windowSizeY/3}
    }});
}



auto betGamObj::init1lvlHPBoosters() -> void
{
    this->setSbTexture();
    this->setHbTexture();

    auto hpPositions = std::vector<sf::Vector2f>{
            {windowSizeX/5, windowSizeY/5*4},
            {windowSizeX/5*4, windowSizeY/5}
    };

    auto sbPositions = std::vector<sf::Vector2f>{
            {windowSizeX/5*4, windowSizeY/5*4},
            {windowSizeX/1.8f, windowSizeY/5*4}
    };

    this->hpBoosterSetter(hpPositions, sbPositions);
}

auto betGamObj::setSbTexture() -> void
{
    if (!this->sbTexture.loadFromFile("../Skull&Bones - FrodoUndead.png"))
        throw std::runtime_error("ERROR::GAME::While loading score booster texture");
}

auto betGamObj::setHbTexture() -> void
{
    if (!this->hbTexture.loadFromFile("../heart.png.png"))
        throw std::runtime_error("ERROR::GAME::While loading health booster texture");

}

    // for 2nd lvl

auto betGamObj::init2ndLvlWalls() -> void
{
    auto type11Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/4.8f, windowSizeY/26.6f},
                    {windowSizeX/6, windowSizeY/3}
            }, {
                    {windowSizeX/4.8f, windowSizeY/26.6f},
                    {windowSizeX/6*2.5f, windowSizeY/5}
            }, {
                    {windowSizeX/4.8f, windowSizeY/26.6f},
                    {windowSizeX/5, windowSizeY/1.5f}
            }, {
                    {windowSizeX/25, windowSizeY/4},
                    {windowSizeX/6 * 4, windowSizeY/3*2}
            }, {
                    {windowSizeX/25, windowSizeY/4.2f},
                    {windowSizeX/9.5f, windowSizeY/3*2}
            }
    };
    auto type21Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/27, windowSizeY/3.5f},
                    {windowSizeX/8 * 6, windowSizeY/6}
            }, {
                    {windowSizeX/25, windowSizeY/4.5f},
                    {windowSizeX/2, windowSizeY/3}
            }, {
                    {windowSizeX/5.5f, windowSizeY/26.6f},
                    {windowSizeX/5.5f, windowSizeY/2}
            }
    };
    this->wallSetter(type11Walls, type21Walls);
}

auto betGamObj::init2ndLvlMobs() -> void
{
    auto mob1Positions = std::vector<sf::Vector2f>{
            {windowSizeX/5*4, windowSizeY/4*3},
            {windowSizeX/5*4, windowSizeY/4},
            {windowSizeX/5*4, windowSizeY/2}
    };
    auto mob2Positions = std::vector<sf::Vector2f>{
            {windowSizeX/3*2, windowSizeY/5},
            {windowSizeX/1.8f, windowSizeY/5*4},
            {windowSizeX/3, windowSizeY/5*4}
    };

    this->lvl1MobSetter(mob1Positions);
    this->lvl2MobSetter(mob2Positions);
}

auto betGamObj::init2lvlHPBoosters() -> void
{
    auto hpPos = std::vector<sf::Vector2f>{
            {windowSizeX/6*5, windowSizeY/5},
            {windowSizeX/5, windowSizeY/6*5}

    };
    auto sbPos = std::vector<sf::Vector2f>{
            {windowSizeX/3*2, windowSizeY/2.3f},
            {windowSizeX/6*5, windowSizeY/3.5f}
    };

    this->hpBoosterSetter(hpPos, sbPos);
}

    // for 3rd level

auto betGamObj::init3rdLvlWalls() -> void
{
    auto type11Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/27, windowSizeY/3.5f},
                    {windowSizeX/8 * 6, windowSizeY/6}
            }, {
                    {windowSizeX/25, windowSizeY/4.5f},
                    {windowSizeX/2, windowSizeY/3}
            }, {
                    {windowSizeX/25, windowSizeY/4.5f},
                    {windowSizeX/5.5f, windowSizeY/3*2}
            }, {
                    {windowSizeX/5.2f, windowSizeY/23},
                    {windowSizeX/5*3.5f, windowSizeY/1.9f}
            }
    };
    auto type21Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/4.8f, windowSizeY/23},
                    {windowSizeX/2.3f, windowSizeY/5*4}
            }, {
                    {windowSizeX/4, windowSizeY/23},
                    {windowSizeX/2.5f, windowSizeY/5}
            }, {
                    {windowSizeX/4.6f, windowSizeY/24},
                    {windowSizeX/10, windowSizeY/1.8f}
            }, {
                    {windowSizeX/25, windowSizeY/4.5f},
                    {windowSizeX/3.5f, windowSizeY/4.5f}
            }
    };
    this->wallSetter(type11Walls, type21Walls);
}

auto betGamObj::init3rdLvlMobs() -> void
{
    auto mob1Positions = std::vector<sf::Vector2f>{
            {windowSizeX/5*4, windowSizeY/4*3},
            {windowSizeX/5*4, windowSizeY/4}
    };
    auto mob2Positions = std::vector<sf::Vector2f>{
            {windowSizeX/8.5f, windowSizeY/1.5f},
            {windowSizeX/2, this->windowSizeY/5*4.5f}
    };

    this->lvl1MobSetter(mob1Positions);
    this->lvl2MobSetter(mob2Positions);

    this->createAdvAtackMob(
            1.5f, 1.5f, 10,
            {windowSizeX / 27, windowSizeY / 18},
            {windowSizeX / 5 * 4, windowSizeY / 5 * 4}
    );
}

auto betGamObj::init3lvlHPBoosters() -> void
{
    auto sbPos = std::vector<sf::Vector2f>{
            {windowSizeX/6*5, windowSizeY/6},
            {windowSizeX/2, windowSizeY/1.65f}
    };
    this->hpBoosterSetter(
            {{windowSizeX/7*6, windowSizeY/7*6}}, sbPos);
}

auto betGamObj::initPortals() -> void
{
    portal1.setSize({windowSizeX/17, windowSizeY/32});
    portal1.setPosition(
            {windowSizeX/5*4, windowSizeY - portal1.getSize().y*2}
    );
    portal1.setFillColor(sf::Color::Green);

    portal2.setSize({windowSizeX/17, windowSizeY/32});
    portal2.setPosition(
            {windowSizeX/5*3.35f, windowSizeY - portal2.getSize().y*2}
    );
    portal2.setFillColor(sf::Color::Cyan);
}

    // tralalelo lvl

auto betGamObj::initTrLvlWalls() -> void
{
    auto type11Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/2, windowSizeY/27},
                    {windowSizeX/4, windowSizeY/4}
            }, {
                    {windowSizeX/25, windowSizeY/2},
                    {windowSizeX/7, windowSizeY/3.6f}
            }, {
                    {windowSizeX/5, windowSizeY/28.5f},
                    {windowSizeX/3*2.2f, windowSizeY/7}
            }, {
                    {windowSizeX/5, windowSizeY/28.5f},
                    {windowSizeX/6, windowSizeY/7}
            }
    };
    auto type21Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/2, windowSizeY/27},
                    {windowSizeX/4, windowSizeY/4*3}
            }, {
                    {windowSizeX/25, windowSizeY/2},
                    {windowSizeX/6*5, windowSizeY/3.6f}
            }, {
                    {windowSizeX/5, windowSizeY/28.5f},
                    {windowSizeX/3*2.2f, windowSizeY/7*6}
            }, {
                    {windowSizeX/5, windowSizeY/28.5f},
                    {windowSizeX/6, windowSizeY/7*6}
            }
    };
    this->wallSetter(type11Walls, type21Walls);
}
auto betGamObj::initTrLvlMobs() -> void
{
    auto mobPositions = std::vector<sf::Vector2f>{
            {windowSizeX/4, windowSizeY/3},
            {windowSizeX/4 + windowSizeX/10, windowSizeY/3},
            {windowSizeX/4 + 2*windowSizeX/10, windowSizeY/3},
            {windowSizeX/4 + 3*windowSizeX/10, windowSizeY/3},
            {windowSizeX/4 + 4*windowSizeX/10, windowSizeY/3},
            {windowSizeX/4 + 5*windowSizeX/10, windowSizeY/3},

            {windowSizeX/4, windowSizeY/3*1.5f},
            {windowSizeX/4 + windowSizeX/10, windowSizeY/3*1.5f},
            {windowSizeX/4 + 2*windowSizeX/10, windowSizeY/3*1.5f},
            {windowSizeX/4 + 3*windowSizeX/10, windowSizeY/3*1.5f},
            {windowSizeX/4 + 4*windowSizeX/10, windowSizeY/3*1.5f},
            {windowSizeX/4 + 5*windowSizeX/10, windowSizeY/3*1.5f}

    };
    this->lvl1MobSetter(mobPositions);
}
auto betGamObj::initTrlvlHPBoosters() -> void
{
    auto hpPositions = std::vector<sf::Vector2f>{
            {windowSizeX/2, windowSizeY/2},
            {windowSizeX/2 - windowSizeX/15, windowSizeY/2},
            {windowSizeX/2 + windowSizeX/15, windowSizeY/2}
    };
    this->hpBoosterSetter(hpPositions, {});
}

    // for larila

auto betGamObj::initLarLvlWalls() -> void
{

    auto type11Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/28, windowSizeY/3.7f},
                    {windowSizeX/4, windowSizeY/4.5f}
            }, {
                    {windowSizeX/28, windowSizeY/3.7f},
                    {windowSizeX/4 + 2*windowSizeX/5.5f, windowSizeY/4.5f}
            }, {
                    {windowSizeX/4.5f, windowSizeY/28},
                    {windowSizeX/6, windowSizeY/8*6.5f}
            }, {
                    {windowSizeX/4.3f, windowSizeY/28},
                    {windowSizeX/3*2.3f, windowSizeY/8*6.5f}
            }
    };
    auto type21Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/28, windowSizeY/3.7f},
                    {windowSizeX/4 + windowSizeX/5.5f, windowSizeY/4.5f}
            }, {
                    {windowSizeX/28, windowSizeY/3.7f},
                    {windowSizeX/4 + 3*windowSizeX/5.5f, windowSizeY/4.5f}
            }, {
                    {windowSizeX/4.5f, windowSizeY/28},
                    {windowSizeX/2.2f, windowSizeY/8*5.7f}
            }
    };
    this->wallSetter(type11Walls, type21Walls);
}

auto betGamObj::initLarLvlMobs() -> void {
    auto positions = std::vector<sf::Vector2f>{
            {windowSizeX/3, windowSizeY/3},
            {windowSizeX/3 + windowSizeX/5.5f, windowSizeY/3},
            {windowSizeX/3 + 2*windowSizeX/5.5f, windowSizeY/3},
            {windowSizeX/3 + 3*windowSizeX/5.5f, windowSizeY/6},
            {windowSizeX/3.5f, windowSizeY/9*8},
            {windowSizeX/3 + 3*windowSizeX/5.5f, windowSizeY/9*8},
    };

    std::ranges::for_each(positions, [&](const sf::Vector2f& pos) {
        this->createAdvAtackMob(
                1.35f, 1.35f, 10,
                {windowSizeX / 27, windowSizeY / 18}, pos
        );
    });
}

auto betGamObj::initLarlvlHPBoosters() -> void {
    auto positions = std::vector<sf::Vector2f>{
            {windowSizeX/3, windowSizeY/2.7f},
            {windowSizeX/3 + windowSizeX/5.5f, windowSizeY/2.7f},
            {windowSizeX/3 + 2*windowSizeX/5.5f, windowSizeY/2.7f}
    };
    this->hpBoosterSetter({}, positions);
}

    // for 4th lvl

auto betGamObj::init4thLvlWalls() -> void
{
    auto type2Walls = std::vector<std::pair<sf::Vector2f, sf::Vector2f>>{
            {
                    {windowSizeX/4.2f, windowSizeY/23},
                    {windowSizeX/5.5f, windowSizeY/3}
            }, {
                    {windowSizeX/25, windowSizeY/4},
                    {windowSizeX/5*3.5f, windowSizeY/5.5f}
            }, {
                    {windowSizeX/25, windowSizeY/4},
                    {windowSizeX/5*3.8f, windowSizeY/1.75f}
            }, {
                    {windowSizeX/28, windowSizeY/3.7f},
                    {windowSizeX/5, windowSizeY/1.75f}
            }, {
                    {windowSizeX/4.8f, windowSizeY/23},
                    {windowSizeX/2.5f, windowSizeY/5}
            }, {
                    {windowSizeX/28, windowSizeY/3.7f},
                    {windowSizeX/5*2.85f, windowSizeY/2.5f}
            }, {
                    {windowSizeX/6.05f, windowSizeY/23},
                    {windowSizeX/6*5, windowSizeY/2.3f}
            }, {
                    {windowSizeX/8.5f, windowSizeY/23},
                    {0, windowSizeY/2.1f}
            }
    };
    this->wallSetter({{
        {windowSizeX/4.8f, windowSizeY/23}, {windowSizeX/2.3f, windowSizeY/4*3}
    }}, type2Walls);
}

auto betGamObj::init4thLvlMobs() -> void
{
    auto mob1Positions = std::vector<sf::Vector2f>{
            {windowSizeX/5*4, windowSizeY/2},
            {windowSizeX/5*4, windowSizeY/4}
    };
    auto mob3Positions = std::vector<sf::Vector2f>{
            {windowSizeX/7*3, windowSizeY/6*5},
            {windowSizeX/7*4.5f, windowSizeY/6*5}
    };

    this->lvl1MobSetter(mob1Positions);

    std::ranges::for_each(mob3Positions, [&](const sf::Vector2f& pos) {
        this->createAdvAtackMob(
                1.35f, 1.35f, 10,
                {windowSizeX / 27, windowSizeY / 18}, pos
        );
    });
    this->createBossMob(
            1.75f, 1.75f, 22,
            {windowSizeX / 22, windowSizeY / 14},
            {windowSizeX / 5 * 4, windowSizeY / 5 * 4}
    );
}

auto betGamObj::init4thLvlHPBoosters() -> void {
    auto hbPos = std::vector<sf::Vector2f>{
            {windowSizeX / 7 * 6.5f, windowSizeY / 5},
            {windowSizeX / 7 * 6.5f, windowSizeY / 6 * 5},
            {windowSizeX / 1.8f,     windowSizeY / 7 * 6}
    };
    this->hpBoosterSetter(
            hbPos, {{windowSizeX / 2, windowSizeY / 2}});
}

    // Text inits

auto betGamObj::initFont() -> void
{
        if (!this->font.loadFromFile("../dpcomic.ttf"))
            throw std::runtime_error("ERROR::GAMEFONT::While loading from file");
}

auto betGamObj::initLevelText() -> void
{
    this->textSetter(
        levelText, 40, sf::Color::White
        , {windowSizeX/2, windowSizeY/32}, std::string("Level 01")
    );
}

auto betGamObj::initHPText() -> void
{
    this->textSetter(
            hpAndPointsText, 35, sf::Color::White
            , {windowSizeX/2,windowSizeY/16},
            std::string("Health: " + std::to_string(player.playerHP) +
                        ", Points : " + std::to_string(player.playerPoints))
    );
}

auto betGamObj::initTimerText() -> void
{
    this->textSetter(
            timerText, 45, sf::Color::Green
            , {windowSizeX/5*4, windowSizeY/32},
            std::string("")
    );
}

auto betGamObj::initCoolnessText() -> void
{
    this->textSetter(
            coolness, 55, sf::Color::White
            , {windowSizeX/5, windowSizeY/32},
            std::string("Your Aura:\nKinda Mid")
    );
}

auto betGamObj::initOneShottersText() -> void
{
    this->textSetter(
            oneShottersText, 50, sf::Color::Green
            , {windowSizeX/8, windowSizeY/7*6},
            std::string("")
    );
}

auto betGamObj::initTimeScoreText() -> void
{
    this->textSetter(
            timeScore, 60, sf::Color::Green
            , {windowSizeX/5*4.55f, windowSizeY/32},
            std::string("+0")
    );
}

auto betGamObj::initSbText() -> void
{
    this->textSetter(
            scoreBoosterText, 65, sf::Color(252, 15, 192)
    );
}

auto betGamObj::initHbText() -> void
{
    this->textSetter(
            healthBoosterText, 65, sf::Color::Green
    );
}

auto betGamObj::initPortalText() -> void {
    this->textSetter(
            portalText, 60, sf::Color::Yellow,
            {windowSizeX/5*3.4f, windowSizeY - portal1.getSize().y*4.5f},
            std::string("Choose your entry")
    );
}

auto betGamObj::initShopText() -> void {
    this->textSetter(
            shopText, 60, sf::Color::Green,
            {windowSizeX/2.5f, windowSizeY/7*6},
            std::string("Press 'M' to enter shop")
    );
}

    // init helpers

auto betGamObj::hpBoosterSetter(
        const std::vector<sf::Vector2f>& hpPos,
        const std::vector<sf::Vector2f>& sbPos
) -> void {
    std::for_each(hpPos.begin(), hpPos.end(), [&](const sf::Vector2f& hpPos) {
        createHealthBooster(hpPos);
    });
    std::for_each(sbPos.begin(), sbPos.end(), [&](const sf::Vector2f& sbPos) {
        createScoreBooster(sbPos);
    });
}

auto betGamObj::textSetter(
        sf::Text &text, const int &cSize, const sf::Color &color
) -> void {
    text.setFont(this->font);
    text.setCharacterSize(cSize);
    text.setFillColor(color);
}
auto betGamObj::textSetter(
        sf::Text &text, const int &cSize, const sf::Color &color,
        const sf::Vector2f &pos, const std::string &content
) -> void {
    this->textSetter(text, cSize, color);
    text.setPosition(pos);
    text.setString(content);
}

auto betGamObj::wallSetter(
        const std::vector<std::pair<sf::Vector2f, sf::Vector2f>> &type1Walls,
        const std::vector<std::pair<sf::Vector2f, sf::Vector2f>> &type2Walls
) -> void {
    std::for_each(type1Walls.begin(), type1Walls.end(), [&](
                const std::pair<sf::Vector2f, sf::Vector2f>& property) {
        createWall(property.first, property.second, type1Wall);
    });
    std::for_each(type2Walls.begin(), type2Walls.end(), [&](
            const std::pair<sf::Vector2f, sf::Vector2f>& property) {
        createWall(property.first, property.second, type2Wall);
    });
}

auto betGamObj::lvl1MobSetter(
        const std::vector<sf::Vector2f> &positions) -> void {
    std::ranges::for_each(positions, [&](const sf::Vector2f& pos) {
        this->createMob(
                2.f, 2.f, 5,
                sf::Vector2f(windowSizeX/32, windowSizeY/21.33), pos
        );
    });
}
auto betGamObj::lvl2MobSetter(
        const std::vector<sf::Vector2f> &positions) -> void {
    std::ranges::for_each(positions, [&](const sf::Vector2f& pos) {
        this->createAtackMob(
                1.35f, 1.35f, 6,
                {windowSizeX / 38, windowSizeY / 25},
                pos
        );
    });
}


// Constructors / Destructors

betGamObj::betGamObj() : window(
        sf::VideoMode::getDesktopMode(), "Zaza 2",
        sf::Style::Titlebar | sf::Style::Close
) {
    this->window.setFramerateLimit(240);
    this->windowSizeX = this->window.getSize().x;
    this->windowSizeY = this->window.getSize().y;

    this->initVariables();
    this->initWindow();

    this->gMenu = Menu();
    gMenu.setWindow(&this->window);
    gMenu.setClock(&this->clock);
    gMenu.initialisations();

    this->shop = Shop();
    

    this->initFont();
    this->initLevelText();
    this->initHPText();
    this->initTimerText();
    this->initCoolnessText();
    this->initShopText();
    this->initOneShottersText();

    this->initTimeScoreText();
    this->initSbText();
    this->initHbText();

}

betGamObj::~betGamObj()
{
}

auto betGamObj::setFirstLevel() -> void
{
    this->isGameInitialized = true;
    this->clock.restart();
    this->timer = sf::Time::Zero;

    this->lvl = Level::first;
    this->initPlayer();

    this->initMobs();
    this->initWalls();
    this->init1lvlHPBoosters();
}


auto betGamObj::setSecondLevel() -> void
{
    this->is2ndlvlInitialized = true;

    this->clock.restart();
    this->timer = sf::Time::Zero;

    this->player.setPosition(windowSizeX/51.2f, windowSizeY/32);
    this->init2ndLvlWalls();
    this->init2ndLvlMobs();
    this->init2lvlHPBoosters();
}

auto betGamObj::setThirdLevel() -> void
{
    this->is3rdlvlInitialized = true;

    this->clock.restart();
    this->timer = sf::Time::Zero;

    this->player.setPosition(windowSizeX/51.2f, windowSizeY/32);
    this->init3rdLvlWalls();
    this->init3rdLvlMobs();
    this->init3lvlHPBoosters();
    this->initPortals();
}

auto betGamObj::setTralaleroLevel() -> void
{
    this->isTrLvlInitialized = true;

    this->clock.restart();
    this->timer = sf::Time::Zero;

    this->player.setPosition(windowSizeX/51.2f, windowSizeY/32);
    this->initTrLvlWalls();
    this->initTrLvlMobs();
    this->initTrlvlHPBoosters();
}
auto betGamObj::setLiriliLevel() -> void {
    this->isLarLvlInitialized = true;

    this->clock.restart();
    this->timer = sf::Time::Zero;

    this->player.setPosition(windowSizeX/51.2f, windowSizeY/32);
    this->initLarLvlWalls();
    this->initLarLvlMobs();
    this->initLarlvlHPBoosters();
}

auto betGamObj::setFourthLevel() -> void
{
    this->is4thLvlInitialized = true;

    this->clock.restart();
    this->timer = sf::Time::Zero;

    this->player.setPosition(windowSizeX/51.2f, windowSizeY/32);
    this->init4thLvlWalls();
    this->init4thLvlMobs();
    this->init4thLvlHPBoosters();
}

    // Unsets

auto betGamObj::unset() -> void
{
    this->unsetWalls();
    this->unsetMobs();
    this->unsetHPBoosters();
    this->portalsActivated = false;
}

auto betGamObj::unsetWalls() -> void
{
    this->walls.clear();
}

auto betGamObj::unsetMobs() -> void
{
    this->mobs.clear();
    this->atackMobs.clear();
}

auto betGamObj::unsetHPBoosters() -> void
{
    this->healthBoosters.clear();
    this->scoreBoosters.clear();
}

// Checks

bool betGamObj::getWindowisOpen()
{
    return this->window.isOpen();
}

auto betGamObj::intersectsWMob(const Player::Bullet& bullet)-> bool
{
    auto lamb = [&](Mob& mob) -> bool {
        if (
            mob.getGlobalBounds().intersects(bullet.getGlobalBounds())
        ) {
            mob.mobHP -= bullet.damage;
            this->player.playerPoints += 1;
            return true;
        } return false;
    };

    auto it1 = std::ranges::find_if(mobs, lamb);
    auto it2 = std::ranges::find_if(atackMobs, lamb);

    return it1 != mobs.end() || it2 != atackMobs.end();
}

auto betGamObj::timeScored(int score) -> void
{
    this->timeScore.setString("+" + std::to_string(score));
    this->timeScoreClock.restart();

    this->ifTimeScored = true;
}

auto betGamObj::sbScored(sf::Vector2f pos) -> void
{
    scoreBoosterText.setPosition(pos);
    scoreBoosterText.setString("+5p");
    sbClock.restart();

    this->ifSbScored = true;
}

auto betGamObj::hbScored(sf::Vector2f pos) -> void
{
    healthBoosterText.setPosition(pos);
    healthBoosterText.setString("+5h");
    hbClock.restart();

    this->ifHbScored = true;
}


//Creates


auto betGamObj::createMob(
        float VX, float VY, int hp,
      sf::Vector2f size, sf::Vector2f pos, bool random) -> void
{
        auto mob = Mob(VX, VY, hp);
        mob.setTexture(lvl1Mob);
        mob.setScale(
                size.x / lvl1Mob.getSize().x, size.y / lvl1Mob.getSize().y
        );

        mob.size = {
                mob.getLocalBounds().width * mob.getScale().x,
                mob.getLocalBounds().height * mob.getScale().y
        };
        if (random)
        {
            do {
                mob.setPosition(static_cast<float>(
                            rand() % static_cast<int>(this->windowSizeX - mob.size.x)),
                    static_cast<float>(
                            rand() % static_cast<int>(this->windowSizeY  - mob.size.y))
                );
            }
            while (
                    objWallInteraction(mob) ||
                    mob.getGlobalBounds().intersects(player.getGlobalBounds())
            );
        } else
            mob.setPosition(pos);

        this->mobs.push_back(mob);
}

auto betGamObj::createAtackMob(
        float VX, float VY, int hp,
        sf::Vector2f size,
        sf::Vector2f pos
) -> void
{
    auto attackMob = Mob(VX, VY, hp);
    attackMob.setTexture(lvl2Mob);
    attackMob.setScale(
            size.x / lvl1Mob.getSize().x, size.y / lvl2Mob.getSize().y
    );
    attackMob.size = {
            attackMob.getLocalBounds().width * attackMob.getScale().x,
            attackMob.getLocalBounds().height * attackMob.getScale().y
    };

    attackMob.setPosition(pos);
    atackMobs.push_back(attackMob);
}

auto betGamObj::createAdvAtackMob(
        float VX, float VY, int hp, sf::Vector2f size, sf::Vector2f pos
) -> void
{
    auto attackMob = Mob(VX, VY, hp);
    attackMob.setTexture(lvl3Mob);
    attackMob.setScale(
            size.x / lvl1Mob.getSize().x, size.y / lvl1Mob.getSize().y
    );
    attackMob.size = {
            attackMob.getLocalBounds().width * attackMob.getScale().x,
            attackMob.getLocalBounds().height * attackMob.getScale().y
    };
    attackMob.setPosition(pos);

    atackMobs.push_back(attackMob);
}

auto betGamObj::createBossMob(
        float VX, float VY, int hp, sf::Vector2f size, sf::Vector2f pos
) -> void
{
    auto boss = Mob(VX, VY, hp);
    boss.setTexture(lvl4Mob);
    boss.setScale(
            size.x / lvl1Mob.getSize().x, size.y / lvl1Mob.getSize().y
    );
    boss.size = {
            boss.getLocalBounds().width * boss.getScale().x,
            boss.getLocalBounds().height * boss.getScale().y
    };
    boss.setPosition(pos);

    atackMobs.push_back(boss);
}

auto betGamObj::loadMobsTextures() -> void {
    if(!lvl1Mob.loadFromFile("../1lvlMob.png")
        or !lvl2Mob.loadFromFile("../2lvlMob.png")
        or !lvl3Mob.loadFromFile("../3lvlMob.png")
        or !lvl4Mob.loadFromFile("../4lvlMob.png")
    )
        throw std::runtime_error("ERROR::WHILE LOADING MOB TEXTURE");
}

auto betGamObj::loadPlayerTexture() -> void
{
    if (!playerTexture.loadFromFile("../kuromi sanrio-1.png.png"))
        throw std::runtime_error("ERROR::GAME::Player texture loading");
    this->player.setTexture(playerTexture);
}

auto betGamObj::createPlayer(
        float VX, float VY, int hp,
        sf::Vector2f pos
) -> void
{
    this->player = Player(VX, VY, hp);

    this->loadPlayerTexture();
    this->player.setScale(0.12f, 0.12f);
    this->player.size = {
            player.getLocalBounds().width * player.getScale().x,
            player.getLocalBounds().height * player.getScale().y
    };
    this->player.setPosition(pos);
    this->player.playerPoints = 0;
    this->player.isPlayerAlive = true;
}

auto betGamObj::createBullet() -> void
{
    auto bulletSpeed = sf::Vector2f();
    auto radius = 0;
    auto color = sf::Color();

    switch (player.aura) {
        case(Player::PlayerAura::BADDIE):
            radius = 13;
            color = sf::Color(252, 15, 192);
            bulletSpeed = {14.f, 14.f};
            break;
        case(Player::PlayerAura::COOK):
            radius = 10;
            color = sf::Color(255, 192, 203);
            bulletSpeed = {11.5f, 11.5f};
            break;
        case(Player::PlayerAura::MID):
            radius = 7;
            color = sf::Color::White;
            bulletSpeed = {9.f, 9.f};
            break;
    }
    if (this->bullets.size() < bulletsMax)
    {
        auto bullet = Player::Bullet(bulletSpeed, 2);
        bullet.speed = bulletSpeed;

        this->bulletDirecting(bullet, bulletSpeed);
        bullet.setRadius(radius);
        bullet.setFillColor(color);

        bullet.setPosition(player.getPosition().x + player.size.x,
                           player.getPosition().y
        );

        this->bullets.push_back(bullet);
    }
}

auto betGamObj::shootOneShotter() -> void {
    auto bullet = player.oneShotters[player.oneShotters.size() - 1];
    player.oneShotters.pop_back();

    this->bulletDirecting(bullet, bullet.speed);

    bullet.setPosition(player.getPosition().x + player.size.x,
                       player.getPosition().y
    );
    player.shotOneShotters.push_back(bullet);
}

auto betGamObj::bulletDirecting(Player::Bullet &bullet, const sf::Vector2f& bulletSpeed) -> void {
    switch (lastMoveKeyPressed) {
        case 0:
            bullet.speed = sf::Vector2f(0, -bulletSpeed.y);
            break;
        case 1:
            bullet.speed = sf::Vector2f(0, bulletSpeed.y);
            break;
        case 2:
            bullet.speed = sf::Vector2f(-bulletSpeed.x, 0);
            break;
        case 3:
            bullet.speed = sf::Vector2f(bulletSpeed.x, 0);
            break;
        default:
            bullet.speed = sf::Vector2f(bulletSpeed.x, 0);
            break;
    }
}
    // for walls

auto betGamObj::loadWallTexture(
        sf::Texture &texture, const std::string &path
) -> void {
    if(!texture.loadFromFile(path))
        throw std::runtime_error("ERROR::TEXTURE::WHILE LOADING WALLS");
}

auto betGamObj::createWall(
        sf::Vector2f size, sf::Vector2f pos, sf::Color color
) -> void
{
    auto wall = sf::RectangleShape(size);
    wall.setPosition(pos);
    wall.setFillColor(color);
}
auto betGamObj::createWall(
        const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Texture& texture
) -> void {
    auto wall = Wall();
    wall.setPosition(pos);
    wall.setTexture(texture);
    wall.setScale(
            size.x / texture.getSize().x, size.y / texture.getSize().y
    );
    wall.size = {
            player.getLocalBounds().width * wall.getScale().x,
            player.getLocalBounds().height * wall.getScale().y
    };

    walls.push_back(wall);
}

auto betGamObj::createHealthBooster(sf::Vector2f pos) -> void
{
    auto hb = sf::Sprite();
    hb.setTexture(this->hbTexture);
    hb.setScale(5.f, 5.f);

    hb.setPosition(pos);

    this->healthBoosters.push_back(hb);
}

auto betGamObj::createScoreBooster(sf::Vector2f pos) -> void
{
    auto sb = sf::Sprite();
    sb.setTexture(this->sbTexture);
    sb.setScale(1.5f, 2.5f);

    sb.setPosition(pos);

    this->scoreBoosters.push_back(sb);
}


// Interactions

auto betGamObj::ifDamaged(const sf::Vector2f& origPos) -> void
{
    for (auto &mob: this->mobs) {
        if (mob.getGlobalBounds().intersects(player.getGlobalBounds())) {
            mob.mobVelocityY *= -1;
            mob.mobVelocityX *= -1;
            this->player.setPosition(origPos);
            this->player.playerHP -= 1;
        }
    }

    for (auto &attackMob: this->atackMobs) {
        if (
            attackMob.getGlobalBounds().intersects(player.getGlobalBounds())
        ) {
            this->player.setPosition(origPos);
            this->player.playerHP -= 1;
        }
    }

}

template <boundable B>
auto betGamObj::objWallInteraction(const B& obj) -> bool
{
    if(std::ranges::find_if(walls, [&](const Wall& wall) {
        return obj.getGlobalBounds().intersects(wall.getGlobalBounds());
    }) != walls.end())
        return true;
    else
        return false;
}


auto betGamObj::circleIntersectsWMapEnd(const sf::CircleShape &circle) -> bool
{
    return circle.getPosition().x < 0 ||
            circle.getPosition().y < 0 ||
            circle.getPosition().x > this->windowSizeX - circle.getRadius()*2 ||
            circle.getPosition().y > this->windowSizeY - circle.getRadius()*2;
}

auto betGamObj::avoidWalls(
        const Mob &attackMob, const sf::Vector2f& direction) -> sf::Vector2f
{
    auto adjustedDirection = direction;

    auto tempMob = attackMob;

    auto moveX = sf::Vector2f {
        direction.x * attackMob.mobVelocityX, 0.f
    };
    tempMob.setPosition(attackMob.getPosition());
    tempMob.move(moveX);

    auto xBlocked = std::ranges::find_if(walls, [&](const Wall& wall) {
        return wall.getGlobalBounds().intersects(tempMob.getGlobalBounds());
    });

    auto moveY = sf::Vector2f {
            0.f, direction.y * attackMob.mobVelocityY
    };
    tempMob.setPosition(attackMob.getPosition());
    tempMob.move(moveY);

    auto yBlocked = std::ranges::find_if(walls, [&](const Wall& wall) {
        return wall.getGlobalBounds().intersects(tempMob.getGlobalBounds());
    });

    adjustedDirection.x = xBlocked != walls.end()? 0.f: direction.x;
    adjustedDirection.y = yBlocked != walls.end()? 0.f: direction.y;

    return adjustedDirection;
}


//Updating

auto betGamObj::pollEvents() -> void
{
    while (this->window.pollEvent(event)) {
        switch (event.type) {
            case (sf::Event::Closed):
                window.close();
                break;
            case (sf::Event::KeyPressed):
                if (!isShopRunning && event.key.code == sf::Keyboard::Escape) {
                    this->isGameInitialized = false;
                    gMenu.gameStarted = false;
                }
                if(isGameInitialized && event.key.code == sf::Keyboard::M) {
                    if(!isShopInitialized) {
                        this->isShopInitialized = true;
                        this->shop.setPointers(&this->window, &this->player);
                    }
                    isShopRunning = !isShopRunning;
                }
                if(!player.oneShotters.size() == 0 && isGameInitialized && event.key.code == sf::Keyboard::X) {
                    if(!xHeld) {
                        xHeld = true;
                        this->shootOneShotter();
                    } else
                        xHeld = false;
                }
                break;
        }
        if (ifShooting())
            this->createBullet();
    }
}


auto betGamObj::updateAura() -> void
{
    if (player.aura == Player::PlayerAura::COOK && player.playerPoints > 80) {
        player.aura = Player::PlayerAura::BADDIE;
        player.playerVelocityX = 2.6f;
        player.playerVelocityY = 2.6f;
    } else if (player.aura == Player::PlayerAura::MID && player.playerPoints > 50) {
        player.aura = Player::PlayerAura::COOK;
        player.playerVelocityX = 2.3f;
        player.playerVelocityY = 2.3f;
    } else if(player.aura == Player::PlayerAura::MID) {
        player.playerVelocityX = 2.f;
        player.playerVelocityY = 2.f;
    }
}

auto betGamObj::updatePlayer() -> void
{
    // Manual moving

    auto origPos = this->player.getPosition();

    if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::W)
        && this->player.getPosition().y > 0
    ) {
        lastMoveKeyPressed = 0;
        this->player.move(0, -player.playerVelocityY);
    }
    if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::S)
        && this->player.getPosition().y < windowSizeY - player.size.y
    ) {
        lastMoveKeyPressed = 1;
        this->player.move(0, player.playerVelocityY);
    }
    if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)
        && this->player.getPosition().x > 0
    ) {
        lastMoveKeyPressed = 2;
        this->player.move(-player.playerVelocityX, 0);
    }
    if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        && this->player.getPosition().x < windowSizeX - player.size.x
    ) {
        lastMoveKeyPressed = 3;
        this->player.move(player.playerVelocityX, 0);
    }



    // Checking for interactions

    if (objWallInteraction(this->player))
        player.setPosition(origPos);

    this->ifDamaged(origPos);

    // Checking for being alive

    if (this->player.playerHP <= 0)
    {
        this->player.isPlayerAlive = false;

        this->unset();

        this->isGameInitialized = false;
        this->is2ndlvlInitialized = false;
        this->is3rdlvlInitialized = false;
        this->is4thLvlInitialized = false;
        this->isTrLvlInitialized = false;
        this->isLarLvlInitialized = false;

        gMenu.gameStarted = false;
    }
    this->updateAura();
}

auto betGamObj::updateBullets(
        std::vector<Player::Bullet>& bulls) -> void {
    for (auto it = bulls.begin(); it < bulls.end(); it++)
    {
        it->move(it->speed);
        if (
            circleIntersectsWMapEnd(*it) ||
            intersectsWMob(*it) ||
            objWallInteraction(*it)
        ) {
            bulls.erase(it);
        }
    }
}

auto betGamObj::ifShooting() -> bool
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!enterHeld)
        {
            this->enterHeld = true;
        }
    } else
        this->enterHeld = false;
    return enterHeld;
}


auto betGamObj::updateMobs() -> void
{
    for (auto& mob : this->mobs)
    {
        auto origPos = mob.getPosition();

        if (mob.getPosition().x <= 0)
            mob.mobVelocityX = -mob.mobVelocityX;
        if (mob.getPosition().y <= 0)
            mob.mobVelocityY = -mob.mobVelocityY;
        if (mob.getPosition().x >= this->windowSizeX - mob.size.x)
            mob.mobVelocityX = -mob.mobVelocityX;
        if (mob.getPosition().y >= this->windowSizeY - mob.size.y)
            mob.mobVelocityY = -mob.mobVelocityY;

        mob.move(mob.mobVelocityX, mob.mobVelocityY);

        if (
                this->objWallInteraction(mob)
                ) {
            mob.setPosition(origPos);
            switch(rand() % 2) {
                case (0):
                    mob.mobVelocityX = -mob.mobVelocityX;
                    break;
                case (1):
                    mob.mobVelocityY = -mob.mobVelocityY;
                    break;
            }
        }
    }

    this->mobs.erase(std::remove_if(this->mobs.begin(), this->mobs.end(), [](const Mob& mob) {
        return mob.mobHP <= 0;
    }), this->mobs.end());
}

auto betGamObj::updateAtackMobs() -> void
{
    for (auto& attackMob : this->atackMobs)
    {
        auto direction = sf::Vector2f(
                player.getPosition() - attackMob.getPosition()
        );
        auto length = float(
                std::sqrt(direction.x * direction.x + direction.y * direction.y)
        );
        if (length != 0)
            direction /= length;
        auto movement = direction * (attackMob.mobVelocityX/15);
        auto newDirection = this->avoidWalls(attackMob, direction);
        movement = newDirection * (attackMob.mobVelocityX);

        attackMob.move(movement);
    }

    this->atackMobs.erase(std::remove_if(
            this->atackMobs.begin(), this->atackMobs.end(),
            [](const Mob& attackMob) {
                        return attackMob.mobHP <= 0;
                }
            ), this->atackMobs.end()
    );
}

auto betGamObj::areMobsDead() -> bool
{
    if (mobs.empty() && atackMobs.empty()) {
        auto timeScoredLamb = [&](const int& seconds, const int& points) {
            if (static_cast<int>(timer.asSeconds()) < seconds) {
                player.playerPoints += points;
                this->timeScored(points);
            }
        };

        switch (lvl) {
            case (Level::fourth):

                this->isGameInitialized = false;
                this->is2ndlvlInitialized = false;
                this->is3rdlvlInitialized = false;
                this->is4thLvlInitialized = false;
                gMenu.gameStarted = false;
                gMenu.whenWon();

                this->unsetWalls();
                this->unsetHPBoosters();

                break;
            case (Level::tralalero):
            case (Level::lirili):
                timeScoredLamb(25, 10);
                this->lvl = Level::fourth;
                break;
            case (Level::third):
                if(!portalsActivated) {
                    timeScoredLamb(30, 10);
                    portalsActivated = true;
                    this->initPortalText();
                } else {
                    if (player.getGlobalBounds().intersects(portal1.getGlobalBounds())) {
                        this->lvl = Level::tralalero;
                    }
                    if (player.getGlobalBounds().intersects(portal2.getGlobalBounds())) {
                        this->lvl = Level::lirili;
                    }
                }
                break;
            case (Level::second):
                timeScoredLamb(25, 10);
                this->lvl = Level::third;

                break;
            case (Level::first):
                timeScoredLamb(27, 15);
                this->lvl = Level::second;
                break;
        }
        return true;
    } else
        return false;
}

auto betGamObj::updateHPBoosters() -> void
{
    for (
        auto it = healthBoosters.begin(); it < healthBoosters.end(); ++it
    )   {
        if (it->getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            player.playerHP += 5;
            this->hbScored(it->getPosition());
            healthBoosters.erase(it);
        }
    }

    for (
            auto it = scoreBoosters.begin(); it < scoreBoosters.end(); ++it
            )   {
        if (it->getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            player.playerPoints += 5;
            this->sbScored(it->getPosition());
            scoreBoosters.erase(it);
        }
    }
}

auto betGamObj::updateLevelText() -> void
{
    switch (lvl) {
        case (Level::first):
            this->levelText.setString("Level 01/04");
            break;
        case (Level::second):
            this->levelText.setString("Level 02/04");
            break;
        case (Level::third):
            this->levelText.setString("Level 03/04");
            break;
        case (Level::tralalero):
            this->levelText.setString("Level TralaleroTralala");
            break;
        case (Level::lirili):
            this->levelText.setString("Level LiriliLarila");
            break;
        case (Level::fourth):
            this->levelText.setString("Level 04/04");
            break;
    }
}

auto betGamObj::updateHPText() -> void
{
    if (player.playerHP < 20)
        this->hpAndPointsText.setFillColor(sf::Color::Red);
    else
        this->hpAndPointsText.setFillColor(sf::Color::White);

    this->hpAndPointsText.setString(
            "Health: " + std::to_string(player.playerHP) +
            ", Points : " + std::to_string(player.playerPoints)
    );
}

auto betGamObj::updateTimerText() -> void
{
    this->timer = clock.getElapsedTime();
    auto seconds = static_cast<int>(timer.asSeconds());
    if (seconds < 29)
        timerText.setFillColor(sf::Color::Green);
    else if (seconds > 60)
    {
        this->player.playerHP = 0;
        this->unset();
    }
    else if (seconds > 44)
        timerText.setFillColor(sf::Color::Red);
    else if (seconds > 29)
        timerText.setFillColor(sf::Color::Yellow);

    this->timerText.setString(
        "Your time:\n" + std::to_string(seconds)
        + " / 60"
    );
}

auto betGamObj::updateCoolnessText() -> void
{
    switch(player.aura) {
        case (Player::PlayerAura::BADDIE):
            this->coolness.setFillColor(
                    sf::Color(252, 15, 192)
            );
            this->coolness.setString(
                    "Your Aura:\nUr a Baddie"
            );
            break;

        case (Player::PlayerAura::COOK):
            this->coolness.setFillColor(
                    sf::Color(255, 192, 203)
            );
            this->coolness.setString(
                    "Your Aura:\nLet him cook"
            );
            break;
        case (Player::PlayerAura::MID):
            this->coolness.setFillColor(sf::Color::White);
            this->coolness.setString(
                    "Your Aura:\nKinda Mid"
            );
            break;
    }
}

auto betGamObj::updateOneShottersText() -> void
{
    oneShottersText.setString("One shotters: x"
    + std::to_string(player.oneShotters.size()));
}

auto betGamObj::updateTimeScoredText() -> void
{
    if (
        ifTimeScored && timeScoreClock.getElapsedTime() > sf::seconds(2)
    )
        this->ifTimeScored = false;
}

auto betGamObj::updateSbText() -> void
{
    if (
      ifSbScored && sbClock.getElapsedTime() > sf::seconds(1)
    )
        this->ifSbScored = false;
}

auto betGamObj::updateHbText() -> void
{
    if (
        ifHbScored && hbClock.getElapsedTime() > sf::seconds(1)
    )
        this->ifHbScored = false;
}

auto betGamObj::update() -> void
{
    if (this->player.isPlayerAlive)
    {
        this->pollEvents();

        this->areMobsDead();
        this->updateMobs();
        this->updateAtackMobs();

        this->updatePlayer();
        this->updateBullets(this->bullets);
        if(player.shotOneShotters.size() >= 0)
            this->updateBullets(player.shotOneShotters);

        this->updateHPBoosters();

        this->updateLevelText();
        this->updateHPText();
        this->updateTimerText();
        this->updateCoolnessText();
        this->updateOneShottersText();

        this->updateTimeScoredText();
        this->updateSbText();
        this->updateHbText();
    }
}

//Rendering


auto betGamObj::render2ndLvlMobs() -> void
{
    for (auto const& mob : this->mobs)
    {
        this->window.draw(mob);
    }
    for (auto const& attackMob : this->atackMobs)
    {
        this->window.draw(attackMob);
    }
}

auto betGamObj::renderPlayer(sf::RenderTarget& target) -> void
{
    target.draw(this->player);
}

auto betGamObj::renderBullets(const std::vector<Player::Bullet>& bulls) -> void
{
    for (auto const& b : bulls)
    {
        this->window.draw(b);
    }
}

auto betGamObj::renderWalls(sf::RenderTarget& target) -> void
{
    for(auto const& wall : this-> walls)
    {
        target.draw(wall);
    }
}

auto betGamObj::renderPortals(sf::RenderTarget &target) -> void
{
    target.draw(portal1);
    target.draw(portal2);
}

auto betGamObj::renderHPBoosters() -> void
{
    for (auto const& hb : this->healthBoosters)
    {
        this->window.draw(hb);
    }

    for (auto const& sb : this->scoreBoosters)
    {
        this->window.draw(sb);
    }
}


auto betGamObj::renderLevelText(sf::RenderTarget &target) -> void
{
    target.draw(this->levelText);
}

auto betGamObj::renderHPText(sf::RenderTarget &target) -> void
{
    target.draw(this->hpAndPointsText);
}

auto betGamObj::renderTimerText() -> void
{
    this->window.draw(timerText);
}

auto betGamObj::renderCoolnessText() -> void
{
    this->window.draw(coolness);
}
auto betGamObj::renderOneShottersText() -> void
{
    window.draw(oneShottersText);
}
auto betGamObj::renderPortalText() -> void
{
    this->window.draw(portalText);
}
auto betGamObj::renderShopText() -> void
{
    if(lvl == Level::first && timer.asSeconds() < 10)
        this->window.draw(shopText);
}

auto betGamObj::renderTimeScoreText() -> void
{
    if (this->ifTimeScored)
        this->window.draw(timeScore);
}

auto betGamObj::renderSbText() -> void
{
    if (this->ifSbScored)
        this->window.draw(scoreBoosterText);
}

auto betGamObj::renderHbText() -> void
{
    if (this->ifHbScored)
        this->window.draw(healthBoosterText);
}


auto betGamObj::render() -> void
{
    this->window.clear();

    if(lvl == Level::third)
        this->renderPortals(window);
    if(portalsActivated)
        this->renderPortalText();
    this->render2ndLvlMobs();
    this->renderPlayer(this->window);
    this->renderBullets(bullets);
    if(player.shotOneShotters.size() > 0)
        renderBullets(player.shotOneShotters);

    this->renderWalls(this->window);
    this->renderHPBoosters();

    this->renderLevelText(this->window);
    this->renderHPText(this->window);
    this->renderTimerText();
    this->renderCoolnessText();
    this->renderShopText();
    this->renderOneShottersText();

    this->renderTimeScoreText();
    this->renderSbText();
    this->renderHbText();

    this->window.display();
}

auto betGamObj::run() -> void
{
    while (this->getWindowisOpen()) {
        if (!isGameInitialized) {
            this->unset();
            this->setFirstLevel();
        }

        if (this->lvl == Level::second && !is2ndlvlInitialized) {
            this->unset();
            this->setSecondLevel();
        }

        if (this->lvl == Level::third && !is3rdlvlInitialized) {
            this->unset();
            this->setThirdLevel();
        }

        if (this->lvl == Level::tralalero && !isTrLvlInitialized) {
            this->unset();
            this->setTralaleroLevel();
        }

        if (this->lvl == Level::lirili && !isLarLvlInitialized) {
            this->unset();
            this->setLiriliLevel();
        }

        if (this->lvl == Level::fourth && !is4thLvlInitialized) {
            this->unset();
            this->setFourthLevel();
        }

        if (isShopRunning) {
            this->update();
            shop.runShop();
        }
        else if (gMenu.isGameStarted()) {
            this->update();
            this->render();
        } else {
            gMenu.runMenu();
        }
    }
}
