#include "Ghost.h"
#include <cmath>

Ghost::Ghost(sf::Texture& texture, sf::Vector2f startPos, float moveSpeed)
    : sprite(texture),  // ✅ khởi tạo sprite bằng texture
    speed(moveSpeed),
    velocity(0.f, 0.f)
{
    sprite.setPosition(startPos);
}


void Ghost::Update(float dt, sf::Vector2f playerPos)
{
    // Lấy vị trí hiện tại của ghost
    sf::Vector2f ghostPos = sprite.getPosition();

    // Tính vector hướng đến người chơi
    sf::Vector2f direction = playerPos - ghostPos;

    // Chuẩn hóa vector (đưa về độ dài 1)
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
        direction /= length;

    // Cập nhật vận tốc
    velocity = direction * speed;

    // Cập nhật vị trí theo thời gian dt
    sprite.move(velocity * dt);
}

void Ghost::Draw(sf::RenderWindow& window)
{
    // Tạm thời chưa code gì ở đây
    // window.draw(sprite);
}
