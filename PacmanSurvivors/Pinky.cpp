#include "Pinky.h"
#include "AssetManager.h"
#include <cmath>

Pinky::Pinky(sf::Vector2f spawnPos)
    : m_sprite(AssetManager::getInstance().getTexture("Pinky.png")),
    m_speed(180.0f),
    m_velocity(0.f, 0.f),
    m_health(100.f),
	m_knockbackVelocity(0.f, 0.f),
	m_isKnockBack(false)
{
    m_sprite.setPosition(spawnPos);
}

void Pinky::update(float dt, sf::Vector2f playerPos)
{
    if (m_isKnockBack)
    {
        m_sprite.move(m_knockbackVelocity * dt);
        m_knockbackVelocity *= 0.5f; // Giảm dần knockback theo thời gian
        if (std::abs(m_knockbackVelocity.x) < 0.1f && std::abs(m_knockbackVelocity.y) < 0.1f)
        {
            m_knockbackVelocity = sf::Vector2f(0.f, 0.f);
            m_isKnockBack = false;
        }
    }
    else
    {
        sf::Vector2f ghostPos = m_sprite.getPosition();
        sf::Vector2f direction = playerPos - ghostPos;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0)
        {
            direction /= length; // Chuẩn hóa vector hướng
            m_velocity = direction * m_speed;
            m_sprite.move((m_velocity)*dt);
        }
        else
        {
            m_velocity = sf::Vector2f(0.f, 0.f);
        }
    }
}

void Pinky::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

sf::FloatRect Pinky::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

void Pinky::takeDamage(int damage)
{
    m_health -= damage;
    if (m_health < 0.f)
        m_health = 0.f;
}

bool Pinky::isDead() const
{
    return m_health <= 0.f;
}

int Pinky::getCollisionDamage() const
{
    return 10;
}

sf::Vector2f Pinky::getPosition() const
{
    return m_sprite.getPosition();
}

void Pinky::setPosition(sf::Vector2f pos)
{
    m_sprite.setPosition(pos);
}

void Pinky::applySeparation(const std::vector<std::unique_ptr<IEnemy>>& others)
{
    sf::Vector2f repel(0.f, 0.f);
    float desiredDistance = 40.f; // khoảng cách tối thiểu giữa quái

    for (auto& other : others)
    {
        if (other.get() == this) continue;

        sf::Vector2f diff = m_sprite.getPosition() - other->getPosition();
        float len = std::sqrt(diff.x * diff.x + diff.y * diff.y);
        if (len > 0 && len < desiredDistance)
        {
            diff /= len; // hướng đẩy
            repel += diff * (desiredDistance - len);
        }
    }

    m_sprite.move(repel * 0.2f); // đẩy nhẹ ra
}

int Pinky::getXPReward() const
{
    return 15;
}

void Pinky::applyKnockback(sf::Vector2f direction, float force)
{
	m_knockbackVelocity += direction * force;
	m_isKnockBack = true;
}
