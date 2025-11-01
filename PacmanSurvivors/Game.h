#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public:
	Game();	//hàm dựng
	void Run();	//hàm chạy game
private:
	//các hàm bên trong Game
	void processInput();
	void update(float dt);
	void render();

	sf::RenderWindow m_Window;	//cửa sổ game
	sf::Clock m_Clock;	//đồng hồ để tính delta time

	Player m_Player; //đối tượng người chơi
};