#include "OrbitalWeaponUpgrade.h"
#include "OrbitalWeapon.h"
#include <memory>
OrbitalWeaponUpgrade::OrbitalWeaponUpgrade()
{
}
void OrbitalWeaponUpgrade::applyUpgrade(Player& player)
{
	player.addWeapon(std::make_unique<OrbitalWeapon>());
}
std::string OrbitalWeaponUpgrade::getName() const
{
	return "Orbital Weapon Upgrade";
}