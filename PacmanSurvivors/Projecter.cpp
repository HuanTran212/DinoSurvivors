#include "Projectile.h"
#include <cmath>

Projectile::Projectile(const sf::Texture& texture, sf::Vector2f playerPos, sf::Vector2f dir, float speed)
	:m_sprite(texture), m_direction(dir), m_velocity(0.f, 0.f), m_speed(speed)
{
	m_sprite.setPosition(playerPos);
	m_sprite.setScale({ 0.5f, 0.5f });

	// Chuẩn hóa vector hướng (Normalize)
	float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
	if (length != 0) {
		m_velocity = dir / length;
	}
	else {
		m_velocity = { 0.f, -1.f }; // Mặc định bắn lên trên nếu hướng = 0
	}
}

void Projectile::update(float dt)
{
	m_sprite.move(m_direction * (m_speed * dt));
}

void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::Vector2f Projectile::getPosition() const{
	return m_sprite.getPosition();
}

sf::FloatRect Projectile::getGlobalBounds() const{
	return m_sprite.getGlobalBounds();
}