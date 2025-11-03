#pragma once

#include <SFML/Graphics.hpp>

class IGameState
{
public:
	virtual ~IGameState() = default;
	// Xử lý sự kiện đầu vào
	virtual void processInput(sf::RenderWindow& window) = 0;
	// Cập nhật trạng thái game
	virtual void update(float dt) = 0;
	// Vẽ nội dung lên cửa sổ
	virtual void render(sf::RenderWindow& window) = 0;

protected:
	IGameState() = default;
};