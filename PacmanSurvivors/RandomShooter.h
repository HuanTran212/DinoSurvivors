#pragma once
#include "IWeapon.h"
#include "Animator.h"
#include <SFML/Graphics.hpp>

class RandomShooter : public IWeapon
{
public:
    RandomShooter();

    void update(float dt,
        sf::Vector2f playerPos,
        std::vector<Projectile>& projectiles,
        const std::vector<std::unique_ptr<IEnemy>>& enemies) override;
    void draw(sf::RenderWindow& window) override;
private:
    float m_fireRate;
    float m_fireTimer;
};