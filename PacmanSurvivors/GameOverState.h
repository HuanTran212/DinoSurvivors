#pragma once
#include <SFML/Graphics.hpp>
#include "IGameState.h"
#include "Game.h"

class GameOverState : public IGameState
{
public:
    GameOverState(Game& game, int finalLevel, bool isWin);

    void processInput() override;
    void update(float dt) override;
    void drawUI() override;
    void drawWorld() override; // Không vẽ thế giới
private:
    Game& m_game;
    sf::Font m_font;

    sf::RectangleShape m_overlay;
    sf::Text m_gameOverText;
    sf::Text m_scoreText;
    sf::Text m_restartText;
};