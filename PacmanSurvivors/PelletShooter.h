#pragma once
#include "IWeapon.h"
#include "AssetManager.h"

class PelletShooter : public IWeapon {
private:
    float m_fireRate;   // khoảng cách giữa hai lần bắn (giây)
    float m_fireTimer;  // bộ đếm thời gian

public:
    PelletShooter();
    void update(float dt, sf::Vector2f playerPos, std::vector<Projectile>& Projectile) override;
    void draw(sf::RenderWindow& window) override;
};
