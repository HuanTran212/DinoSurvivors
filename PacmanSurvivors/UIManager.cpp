#include "UIManager.h"
#include "AssetManager.h"
#include <string>
#include <iomanip>
#include <sstream>

UIManager::UIManager()
	: m_font(AssetManager::getInstance().getFont("pixel.ttf")),
    m_hpText(m_font),
    m_xpText(m_font),
	m_levelText(m_font),
    m_timeText(m_font)
{
    // Cài đặt cho HP Text
    m_hpText.setFont(m_font);
    m_hpText.setCharacterSize(24);
    m_hpText.setFillColor(sf::Color::Red);
    m_hpText.setPosition({ 20.f, 10.f }); // Vị trí ở góc trên bên trái
    m_hpText.setString("HP: 100"); // Giá trị mặc định

    // Cài đặt cho Level Text
    m_levelText.setFont(m_font);
    m_levelText.setCharacterSize(24);
    m_levelText.setFillColor(sf::Color::White);
    m_levelText.setPosition({ 20.f, 40.f }); // Vị trí ở dưới HP
    m_levelText.setString("LVL: 1"); // Giá trị mặc định

    // Cài đặt cho XP Text
    m_xpText.setFont(m_font);
    m_xpText.setCharacterSize(24);
    m_xpText.setFillColor(sf::Color::Cyan);
    m_xpText.setPosition({ 20.f, 70.f }); // Vị trí ở dưới Level
    m_xpText.setString("XP: 0 / 100"); // Giá trị mặc định

    m_timeText.setFont(m_font);
    m_timeText.setCharacterSize(30);
    m_timeText.setFillColor(sf::Color::White);
    m_timeText.setPosition({ 640.f - 50.f, 10.f });
    m_timeText.setString("00:00");
}

void UIManager::update(const Player& player, float gameTime)
{
	int xpToNextLevel = player.getXPToNextLevel();
	int playerHP = player.getHP();
	int playerMaxHP = player.getMaxHP();
	int playerLevel = player.getLevel();
	int playerXP = player.getXP();
    // Dùng std::to_string để chuyển số (int) thành chữ (string)
    m_hpText.setString("HP: " + std::to_string(playerHP) + " / " + std::to_string(playerMaxHP));
    m_levelText.setString("LVL: " + std::to_string(playerLevel));
    m_xpText.setString("XP: " + std::to_string(playerXP) + " / " + std::to_string(xpToNextLevel));

    int totalSeconds = static_cast<int>(gameTime);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;

    m_timeText.setString(ss.str());
}

void UIManager::draw(sf::RenderWindow& window)
{
    window.draw(m_hpText);
    window.draw(m_levelText);
    window.draw(m_xpText);
    window.draw(m_timeText);
}