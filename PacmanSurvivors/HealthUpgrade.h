#pragma once
#include "IUpgrade.h"
#include "Player.h"

class HealthUpgrade : public IUpgrade {
public:
	HealthUpgrade();
	void applyUpgrade(Player& player);
	std::string getName() const;
private:
	int m_hpToAdd;
};