#pragma once
#include <string>

class Player;

class IUpgrade
{
public:
	~IUpgrade() = default;

	virtual void applyUpgrade(Player& player) = 0;

	virtual std::string getName() const = 0;
};
