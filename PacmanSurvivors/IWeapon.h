#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"

class IWeapon {
public:
    virtual ~IWeapon() {}
    virtual void Update(float dt, sf::Vector2f playerPos, std::vector<Projectile>& projectiles) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
};