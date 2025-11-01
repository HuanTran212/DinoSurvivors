#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Sprite m_sprite;
    float m_speed;
	int m_hp;

public:
    Player();
    void handleInput(float dt);
    void update(float dt);
    void draw(sf::RenderWindow& window);
};
