#include "HealthUpgrade.h"

HealthUpgrade::HealthUpgrade():
	m_hpToAdd(10)
{
}

void HealthUpgrade::applyUpgrade(Player& player)
{
	player.addmaxHP(m_hpToAdd);
}
std::string HealthUpgrade::getName() const
{
	return "Tang 10 mau toi da";
}

