#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <cstdlib>
#include "IEnemy.h"
#include "Ghost.h"
#include "Pinky.h"

enum class EnemyType
{
    Ghost,
    Pinky
};

struct SpawnRule
{
	EnemyType type; // Loại kẻ địch
    float interval; // Tần suất
    int count;      // Số lượng mỗi lần
    float timer;    // Đồng hồ nội bộ của quy tắc này
    SpawnRule(EnemyType t, float i, int c) : type(t), interval(i), count(c), timer(0.f) {}
};
struct GameWave
{
    float startTime{}; // Thời điểm bắt đầu
    float endTime{};   // Thời điểm kết thúc
    std::vector<SpawnRule> rules{}; // Các quy tắc spawn trong làn sóng này
};

class EnemySpawner
{
private:
	std::unique_ptr<IEnemy> createEnemy(EnemyType type, sf::Vector2f spawnPos);
    std::vector<std::unique_ptr<IEnemy>> m_enemies;
	std::vector<GameWave> m_timeLine;
public:
    EnemySpawner();
	~EnemySpawner() = default;

    int update(float dt, sf::Vector2f playerPosition, float totalGameTime);
    void draw(sf::RenderWindow& window);
    const std::vector<std::unique_ptr<IEnemy>>& getEnemies() const;
};
