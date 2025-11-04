#pragma once
#include <SFML/Graphics.hpp>

class UIManager
{
private:
    sf::Font m_font;
    sf::Text m_hpText;
    sf::Text m_scoreText;
    sf::RectangleShape m_hpBarBack;
    sf::RectangleShape m_hpBar;

public:
    UIManager();
    void draw(sf::RenderWindow& window, int playerHP, int maxHP, int score);
};
#pragma once
