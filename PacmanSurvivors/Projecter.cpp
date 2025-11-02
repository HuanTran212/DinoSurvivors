#include "Projectile.h"

Projectile::Projectile(const sf::Texture& texture, sf::Vector2f pos, sf::Vector2f dir, float speed)
	: m_direction(dir), m_speed(speed), m_sprite(texture)
{
	m_sprite.setPosition(pos);
	m_sprite.setScale({ 0.5f, 0.5f });
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