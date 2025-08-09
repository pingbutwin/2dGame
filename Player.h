//
// Created by mihav on 10.05.2025.
//


#pragma once

#include <SFML/Graphics.hpp>
#include <fmt/ranges.h>

struct Player : sf::Sprite
{
    enum class PlayerAura {
        MID, COOK, BADDIE
    };

    PlayerAura aura;

    float playerVelocityX;
    float playerVelocityY;
    int playerHP;
    int playerPoints;
    sf::Vector2f size;
    bool isPlayerAlive;

    Player(float VX, float VY, int HP)
    {
        this->aura = PlayerAura::MID;
        this->playerVelocityX = VX;
        this->playerVelocityY = VY;
        this->playerHP = HP;
        this->playerPoints = 0;
    }
    Player() {}

    struct Bullet : sf::CircleShape {
        sf::Vector2f speed;
        int damage;
        Bullet() {}

        Bullet(const sf::Vector2f& s, int damage) {
            this->speed = s;
            this->damage = damage;
        }
    };
    std::vector<Bullet> oneShotters;
    std::vector<Bullet> shotOneShotters;
};


