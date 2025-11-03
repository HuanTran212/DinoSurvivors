#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"

class IWeapon {
public:
    virtual ~IWeapon() {}
    virtual void update(float dt, sf::Vector2f playerPos, std::vector<Projectile>& Projectile) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};