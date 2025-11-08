#include "UpgradeState.h"
#include "AssetManager.h"
#include "PlayingState.h"
#include <iostream>

UpgradeState::UpgradeState(Game& game) :
	m_game(game),
	m_font(AssetManager::getInstance().getFont("pixel.ttf")),
	m_titleText(m_font)
{
	m_titleText.setFont(m_font);
	m_titleText.setString("Upgrade Your Skills");
	m_titleText.setCharacterSize(48);
	m_titleText.setFillColor(sf::Color::Cyan);
	m_titleText.setStyle(sf::Text::Bold);
	m_titleText.setPosition({ 200.f, 100.f });

	sf::Vector2f windowSize = (sf::Vector2f)m_game.getWindow().getSize();

	m_overlay.setSize(windowSize);
	m_overlay.setPosition({0.f, 0.f});
	m_overlay.setFillColor(sf::Color(0, 0, 0, 55));
}

void UpgradeState::processInput()
{
	sf::RenderWindow& window = m_game.getWindow();
	while (auto event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}
		if (event->is<sf::Event::KeyPressed>())
		{
			auto keyEvent = event->getIf<sf::Event::KeyPressed>();
			if (keyEvent)
			{
				if (keyEvent->code == sf::Keyboard::Key::Enter)
				{
					m_game.popStates();
					return;
				}
			}
		}
	}
}
void UpgradeState::update(float dt)
{

}
void UpgradeState::draw()
{
	m_game.getWindow().draw(m_overlay);
	m_game.getWindow().draw(m_titleText);
}