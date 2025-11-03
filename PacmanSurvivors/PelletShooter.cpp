#include "PelletShooter.h"
#include <iostream>

PelletShooter::PelletShooter()
    : m_fireRate(0.0f), m_fireTimer(1.0f)
{
}

void PelletShooter::update(float dt, sf::Vector2f playerPos, std::vector<Projectile>& pelletShooter) {
    m_fireTimer += dt;
	// Kiểm tra nếu đã đến lúc bắn
    if (m_fireTimer >= m_fireRate) {
        m_fireTimer = 0.f;

        // Bắn đạn về phía bên phải
        const sf::Texture& bulletTex = AssetManager::getInstance().getTexture("pellet.png");
		pelletShooter.push_back(Projectile(bulletTex, playerPos, sf::Vector2f(1.f, 0.f), 100.f));
        std::cout << "Pellet fired!" << std::endl;
    }
}

void PelletShooter::draw(sf::RenderWindow& window) {
    // Vũ khí này không có hình riêng nên không cần vẽ gì
}