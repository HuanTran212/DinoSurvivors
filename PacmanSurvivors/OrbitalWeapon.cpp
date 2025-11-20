#include "OrbitalWeapon.h"
#include <sfml/Graphics.hpp>
#include <cmath>

OrbitalWeapon::OrbitalWeapon()
    : m_angle(0.f),
    m_radius(160.f), // Quay ở bán kính 160 pixel
    m_orbCount(0),     // Bắt đầu với 3 quả cầu
    m_damage(30),
    m_damageCooldown(0.3f), // Mỗi quả cầu chỉ gây sát thương 1 lần/giây
    m_damageTimer(0.f),
    m_knockbackForce(120.f)
{
    // Khởi tạo các quả cầu
    for (int i = 0; i < 3; ++i)
    {  
		addOrb();
    }
}
void OrbitalWeapon::update(float dt,
    sf::Vector2f playerPos,
    std::vector<Projectile>& projectiles,
    const std::vector<std::unique_ptr<IEnemy>>& enemies)
{
    // Tốc độ quay (radian/giây)
    const float PI = 3.14159265f;
    float spinSpeed = 2.0f;
    m_angle += spinSpeed * dt;
    // Cập nhật cooldown sát thương
    m_damageTimer += dt;
    bool canDealDamage = (m_damageTimer >= m_damageCooldown);
    // Di chuyển và cập nhật từng quả cầu
    for (int i = 0; i < m_orbs.size(); ++i)
    {
        // Tính toán vị trí (chia đều các quả cầu trên vòng tròn)
        float currentAngle = m_angle + (i * (2.f * PI / m_orbCount));

        sf::Vector2f offset = { std::cos(currentAngle) * m_radius, std::sin(currentAngle) * m_radius };
        sf::Vector2f orbPos = playerPos + offset;

        // Di chuyển quả cầu
        m_orbs[i]->getSprite().setPosition(orbPos);

        // Chạy animation của quả cầu
        m_orbs[i]->update(dt);

        //TỰ KIỂM TRA VA CHẠM (Nếu cooldown đã sẵn sàng)
        if (canDealDamage)
        {
            sf::FloatRect orbBounds = m_orbs[i]->getSprite().getGlobalBounds();

            for (auto& enemy : enemies)
            {
                if (orbBounds.findIntersection(enemy->getBounds()))
                {
                    enemy->takeDamage(m_damage);
					// Áp dụng knockback
					sf::Vector2f knockbackDir = enemy->getPosition() - playerPos;
					float length = std::sqrt(knockbackDir.x * knockbackDir.x + knockbackDir.y * knockbackDir.y);
					if (length > 0) knockbackDir /= length;
					enemy->applyKnockback(knockbackDir, m_knockbackForce);
                }
            }
        }
    }

    // Reset cooldown nếu đã gây sát thương
    if (canDealDamage)
    {
        m_damageTimer = 0.f;
    }
}
void OrbitalWeapon::draw(sf::RenderWindow& window)
{
    // Vẽ từng quả cầu
    for (auto& orb : m_orbs)
    {
        window.draw(orb->getSprite());
    }
}

float OrbitalWeapon::getKnockbackDirection() const
{
    return m_knockbackForce;
}

void OrbitalWeapon::addOrb()
{
    m_orbCount++; //tăng số lượng
    const sf::Texture& tex = AssetManager::getInstance().getTexture("Suriken.png");
    // tạo sprite mới
    auto newSpritePtr = std::make_unique<sf::Sprite>(tex);
    newSpritePtr->setOrigin({ 8.f, 8.f });
	newSpritePtr->setScale({ 2.f, 2.f }); // scale lên 2 lần
    //tạo animator cho sprite đó
    auto animator = std::make_unique<Animator>(*newSpritePtr); // Truyền giá trị sprite

    // cài đặt animation
    int frameWidth = 16; int frameHeight = 16; int numFrames = 4;
    std::vector<sf::IntRect> animFrames;
    for (int j = 0; j < numFrames; ++j) {
        animFrames.push_back(sf::IntRect({ frameWidth * j, 0 }, { frameWidth, frameHeight }));
    }
    animator->addAnimation("SPIN", animFrames, 0.1f);
    animator->play("SPIN");

    // lưu trữ vào danh sách
    m_orbSprites.push_back(std::move(newSpritePtr));
    m_orbs.push_back(std::move(animator));
}
