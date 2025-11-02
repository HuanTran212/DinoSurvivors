#include "Player.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player() :m_sprite(AssetManager::getInstance().getTexture("pacman.png")), m_hp(3), m_xp(0) {
    m_sprite.setPosition({ 400, 300 });
    m_speed = 200.0f;
}

void Player::handleInput(float dt) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        movement.y -= m_speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        movement.y += m_speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        movement.x -= m_speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        movement.x += m_speed * dt;

    m_sprite.move(movement);
}

void Player::update(float dt, std::vector<Projectile>& projectiles) {
	handleInput(dt);

	// Cập nhật vũ khí
    for (auto& weapon : m_weapons) {
        weapon->Update(dt, m_sprite.getPosition(), projectiles);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

sf::Vector2f Player::getPosition() const {
    return m_sprite.getPosition();
}

int Player::getHP() {
    return m_hp;
}

void Player::takeDamage(int damage) {
    m_hp -= damage;
    std::cout << "Player took " << damage << " damage! HP = " << m_hp << std::endl;
}