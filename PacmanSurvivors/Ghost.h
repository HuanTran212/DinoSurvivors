#pragma once
#include <SFML/Graphics.hpp>

class Ghost
{
private:
    sf::Sprite sprite;       // Hình ảnh con ma
    float speed;             // Tốc độ di chuyển
    sf::Vector2f velocity;   // Hướng di chuyển hiện tại

public:
    Ghost(sf::Texture& texture, sf::Vector2f startPos, float moveSpeed = 100.f);

    void Update(float dt, sf::Vector2f playerPos);
    void Draw(sf::RenderWindow& window);

    // Có thể thêm getter nếu cần
    sf::Vector2f GetPosition() const { return sprite.getPosition(); }
    void SetPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
};
#pragma once
