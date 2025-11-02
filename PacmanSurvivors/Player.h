#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "IWeapon.h"
#include "Projectile.h"

class Player {
private:
    sf::Sprite m_sprite;
    float m_speed;
    int m_hp;
    int m_xp;
    std::vector<std::unique_ptr<IWeapon>> m_weapons;

public:
    Player();

    void handleInput(float dt);
    void update(float dt, std::vector<Projectile>& projectiles);
    void draw(sf::RenderWindow& window);

    void takeDamage(int damage);
    int getHP();

};