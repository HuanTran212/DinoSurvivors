#include "OrbitalWeaponUpgrade.h"
#include "OrbitalWeapon.h"
#include <memory>
OrbitalWeaponUpgrade::OrbitalWeaponUpgrade()
{
}
void OrbitalWeaponUpgrade::applyUpgrade(Player& player)
{
	OrbitalWeapon* existingWeapon = player.getWeapon<OrbitalWeapon>();
	if (existingWeapon)
	{
		existingWeapon->addOrb();
	}
	else
	{
		player.addWeapon(std::make_unique<OrbitalWeapon>());
	}
}
std::string OrbitalWeaponUpgrade::getName() const
{
	return "Suriken";
}