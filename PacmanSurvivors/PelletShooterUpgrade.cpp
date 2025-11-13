#include "PelletShooterUpgrade.h"
#include "Player.h"
#include "PelletShooter.h"

PelletShooterUprade::PelletShooterUprade()
{
}

void PelletShooterUprade::applyUpgrade(Player& player)
{
	player.addWeapon(std::make_unique<PelletShooter>());
}
std::string PelletShooterUprade::getName() const
{
	return "Nearest Shooter";
}