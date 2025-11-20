#include "GameOverState.h"
#include "Game.h"
#include "AssetManager.h"
#include "PlayingState.h" // Để restart game
#include "MainMenuState.h" // Hoặc về menu (tùy chọn)
#include <string>

GameOverState::GameOverState(Game& game, int finalLevel, bool isWin)
    : m_game(game),
	m_gameOverText(AssetManager::getInstance().getFont("pixel.ttf")),
	m_scoreText(AssetManager::getInstance().getFont("pixel.ttf")),
	m_restartText(AssetManager::getInstance().getFont("pixel.ttf")),
    m_font(AssetManager::getInstance().getFont("pixel.ttf"))
{
    sf::Vector2f windowSize = (sf::Vector2f)m_game.getWindow().getSize();

    m_overlay.setSize(windowSize);
	//Chữ Game Over / Victory
    m_gameOverText.setFont(m_font);
    m_gameOverText.setCharacterSize(80);
    m_gameOverText.setStyle(sf::Text::Bold);
    if (isWin)
    {
        SoundManager::getInstance().stopMusic();
        SoundManager::getInstance().playSound("WinGame.wav");
        m_overlay.setFillColor(sf::Color(0, 100, 0, 150));
        m_gameOverText.setString("VICTORY!");
        m_gameOverText.setFillColor(sf::Color::Green);
    }
    else
    {
        SoundManager::getInstance().stopMusic();
        SoundManager::getInstance().playSound("GameOver.wav");
        m_overlay.setFillColor(sf::Color(100, 0, 0, 150));
        m_gameOverText.setString("GAME OVER");
        m_gameOverText.setFillColor(sf::Color::Red);
    }
    // Căn giữa (tương đối)
    m_gameOverText.setPosition({ windowSize.x / 2.f - 250.f, windowSize.y / 2.f - 150.f });

    // Chữ Score (Level đạt được)
    m_scoreText.setFont(m_font);
    m_scoreText.setString("You reached Level " + std::to_string(finalLevel));
    m_scoreText.setCharacterSize(30);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition({ windowSize.x / 2.f - 180.f, windowSize.y / 2.f - 20.f });

    //chữ hướng dẫn
    m_restartText.setFont(m_font);
    m_restartText.setString("Press ENTER to Restart");
    m_restartText.setCharacterSize(25);
    m_restartText.setFillColor(sf::Color::Yellow);
    m_restartText.setPosition({ windowSize.x / 2.f - 190.f, windowSize.y / 2.f + 50.f });
}

void GameOverState::processInput()
{
    sf::RenderWindow& window = m_game.getWindow();
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();

        if (event->is<sf::Event::KeyPressed>())
        {
            auto keyEvent = event->getIf<sf::Event::KeyPressed>();
            if (keyEvent && keyEvent->code == sf::Keyboard::Key::Enter)
            {
                m_game.replaceAllStates(std::make_unique<PlayingState>(m_game));
            }
        }
    }
}

void GameOverState::update(float dt)
{
    // Không cần update gì cả
}

void GameOverState::drawUI()
{
    // Vẽ đè lên màn hình chơi game cũ
    m_game.getWindow().draw(m_overlay);
    m_game.getWindow().draw(m_gameOverText);
    m_game.getWindow().draw(m_scoreText);
    m_game.getWindow().draw(m_restartText);
}
void GameOverState::drawWorld()
{
    // Không vẽ thế giới
}