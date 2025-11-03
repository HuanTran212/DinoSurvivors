// IGameState.h
#pragma once
#include <SFML/Graphics.hpp>

class Game; // Khai báo trước để tránh vòng lặp include

class IGameState
{
public:
    virtual ~IGameState() {} // Hủy ảo

    virtual void HandleInput(Game& game, sf::Event& event) = 0; // Xử lý phím
    virtual void Update(Game& game, float dt) = 0;              // Cập nhật logic
    virtual void Draw(Game& game, sf::RenderWindow& window) = 0;// Vẽ màn hình
};
#pragma once
