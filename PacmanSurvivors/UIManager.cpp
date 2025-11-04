// UIManager.cpp
#include "UIManager.h"
#include <iostream>

UIManager::UIManager()
{
    if (!m_font.loadFromFile("assets/fonts/arial.ttf"))
        std::cerr << "Error loading font\n";

    m_hpBarBack.setSize(sf::Vector2f(200.f, 20.f));
    m_hpBarBack.setFillColor(sf::Color(50, 50, 50));
    m_hpBarBack.setPosition(20.f, 20.f);

    m_hpBar.setSize(sf::Vector2f(200.f, 20.f));
    m_hpBar.setFillColor(sf::Color::Red);
    m_hpBar.setPosition(20.f, 20.f);

    m_hpText.setFont(m_font);
    m_hpText.setCharacterSize(16);
    m_hpText.setFillColor(sf::Color::White);
    m_hpText.setPosition(20.f, 45.f);

    m_scoreText.setFont(m_font);
    m_scoreText.setCharacterSize(16);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition(20.f, 70.f);
}

void UIManager::draw(sf::RenderWindow& window, int playerHP, int maxHP, int score)
{
    float hpPercent = static_cast<float>(playerHP) / static_cast<float>(maxHP);
    m_hpBar.setSize(sf::Vector2f(200.f * hpPercent, 20.f));

    m_hpText.setString("HP: " + std::to_string(playerHP) + " / " + std::to_string(maxHP));
    m_scoreText.setString("Score: " + std::to_string(score));

    window.draw(m_hpBarBack);
    window.draw(m_hpBar);
    window.draw(m_hpText);
    window.draw(m_scoreText);
}
