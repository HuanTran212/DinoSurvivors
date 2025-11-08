#pragma once
#include "IGameState.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

class UpgradeState : public IGameState
{
public:
	UpgradeState(Game& game);

	// Xử lý sự kiện đầu vào
	void processInput() override;
	// Cập nhật trạng thái game
	void update(float dt) override;
	// Vẽ nội dung lên cửa sổ
	void draw() override;
private:
	Game& m_game;
	sf::Font m_font;
	sf::Text m_titleText;
	sf::RectangleShape m_overlay;
};