#include "RandomShooter.h"
#include "Projectile.h"
#include "AssetManager.h"
#include <random>
#include <iostream>

RandomShooter::RandomShooter()
    : m_fireRate(1.5f), // Bắn chậm hơn một chút
    m_fireTimer(0.0f)
{
}

void RandomShooter::update(float dt,
    sf::Vector2f playerPos,
    std::vector<Projectile>& projectiles,
    const std::vector<std::unique_ptr<IEnemy>>& enemies)
{
    m_fireTimer += dt;
    if (m_fireTimer >= m_fireRate)
    {
        // Nếu không có kẻ thù, không làm gì cả
        if (enemies.empty()) {
            return;
        }

        // --- GIẢI THUẬT TÌM KẺ THÙ NGẪU NHIÊN ---
        // 1. Chọn một chỉ số (index) ngẫu nhiên
        int randomIndex = rand() % enemies.size();

        // 2. Lấy con trỏ đến kẻ thù đó
        IEnemy* randomEnemy = enemies[randomIndex].get();

        // 3. Bắn về phía kẻ thù đó
        const sf::Texture& bulletTex = AssetManager::getInstance().getTexture("Random.png");
        sf::Vector2f direction = randomEnemy->getPosition() - playerPos;

        Projectile newProj(bulletTex, playerPos, direction, 400.f, 16, 16, 4);
        projectiles.emplace_back(std::move(newProj));
        m_fireTimer = 0.f;
        std::cout << "RandomShooter fired!" << std::endl;
    }
}

void RandomShooter::draw(sf::RenderWindow& window)
{
}