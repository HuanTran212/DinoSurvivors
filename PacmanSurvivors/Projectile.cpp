#include "Projectile.h"
#include <cmath>

Projectile::Projectile(const sf::Texture& texture, sf::Vector2f playerPos, sf::Vector2f dir, float speed)
	:m_sprite(texture), m_direction(dir), m_velocity(0.f, 0.f), m_speed(speed), m_damage(10), m_isDestroyed(false)
{
	m_sprite.setPosition(playerPos);
	m_sprite.setScale({ 2.f, 2.f });

	// Chuẩn hóa vector hướng (Normalize)
	float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
	if (length != 0) {
		m_velocity = dir / length;
	}
	else {
		m_velocity = { 0.f, -1.f }; // Mặc định bắn lên trên nếu hướng = 0
	}
	m_animator = std::make_unique<Animator>(m_sprite);

	int frameWidth = 32;
	int frameHeight = 16;
	int numFrames = 4;
	float frameTime = 0.1f;

	m_sprite.setOrigin({ frameWidth / 2.f, frameHeight / 2.f });
	float angleRad = std::atan2(m_velocity.y, m_velocity.x);
	float angleDeg = angleRad * 180.f / 3.14159265f;
	m_sprite.setRotation(sf::degrees(angleDeg)); // +90 để điều chỉnh hướng sprite

	std::vector<sf::IntRect> animFrames;
	for (int i = 0; i < numFrames; ++i)
	{
		animFrames.push_back(sf::IntRect({ frameWidth * i, 0 }, { frameWidth, frameHeight }));
	}
	m_animator->addAnimation("SPIN", animFrames, frameTime);
	m_animator->play("SPIN");
}

Projectile::Projectile(Projectile&& other) noexcept
	: m_sprite(std::move(other.m_sprite)),
	m_direction(other.m_direction),
	m_velocity(other.m_velocity),
	m_speed(other.m_speed),
	m_damage(other.m_damage),
	m_isDestroyed(other.m_isDestroyed),
	m_animator(std::move(other.m_animator))
{
	if (m_animator) {
		m_animator->setSprite(m_sprite);
	}
}

Projectile& Projectile::operator=(Projectile&& other) noexcept
{
	if (this != &other)
	{
		m_sprite = std::move(other.m_sprite);
		m_direction = other.m_direction;
		m_velocity = other.m_velocity;
		m_speed = other.m_speed;
		m_damage = other.m_damage;
		m_isDestroyed = other.m_isDestroyed;
		m_animator = std::move(other.m_animator);
		if (m_animator) {
			m_animator->setSprite(m_sprite);
		}
	}
	return *this;
}

int Projectile::getDamage() const
{
	return 35;
}

void Projectile::setDamage(int damage)
{
	m_damage = damage;
}

void Projectile::update(float dt)
{
	if (m_animator)
	{
		m_animator->update(dt);
	}
	m_sprite.move(m_velocity * (m_speed * dt));
}

void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Projectile::destroy()
{
	m_isDestroyed = true;
}

bool Projectile::isDestroyed() const
{
	return m_damage <= 0 || m_isDestroyed;
}

sf::Vector2f Projectile::getPosition() const{
	return m_sprite.getPosition();
}

sf::FloatRect Projectile::getBounds() const{
	return m_sprite.getGlobalBounds();
}