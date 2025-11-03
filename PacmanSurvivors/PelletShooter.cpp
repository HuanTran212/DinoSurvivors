#include "PelletShooter.h"
#include <iostream>

PelletShooter::PelletShooter()
    : m_fireRate(0.5f), m_fireTimer(0.0f)
{
}

void PelletShooter::Update(float dt, sf::Vector2f playerPos, std::vector<Projectile>& projectiles) {
    m_fireTimer += dt;

    if (m_fireTimer >= m_fireRate) {
        m_fireTimer = 0.f;

        // Bắn đạn về phía bên phải
        const sf::Texture& bulletTex = AssetManager::getInstance().getTexture("pellet.png");
        projectiles.emplace_back(bulletTex, playerPos, sf::Vector2f(1.f, 0.f), 400.f);
        std::cout << "Pellet fired!" << std::endl;
    }
}

void PelletShooter::Draw(sf::RenderWindow& window) {
    // Vũ khí này không có hình riêng nên không cần vẽ gì
}