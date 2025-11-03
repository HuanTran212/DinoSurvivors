#pragma once
#include <SFML/Graphics.hpp>

class Projectile {
private:
    sf::Sprite m_sprite;
    sf::Vector2f m_direction;
    sf::Vector2f m_velocity;
    float m_speed;
public:
    Projectile(const sf::Texture& texture, sf::Vector2f playerPos, sf::Vector2f dir, float speed);

    void update(float dt);
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
};
