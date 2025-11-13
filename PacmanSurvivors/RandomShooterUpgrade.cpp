#include "RandomShooterUpgrade.h"
#include "Player.h"
#include "RandomShooter.h"

RandomShooterUpgrade::RandomShooterUpgrade()
{
}
void RandomShooterUpgrade::applyUpgrade(Player& player)
{
	// Thêm một RandomShooter mới vào Player
	player.addWeapon(std::make_unique<RandomShooter>());
}
std::string RandomShooterUpgrade::getName() const
{
	return "Random Shooter";
}