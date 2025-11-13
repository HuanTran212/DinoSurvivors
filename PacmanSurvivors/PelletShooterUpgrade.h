#pragma once
#include "IUpgrade.h"

class PelletShooterUprade : public IUpgrade
{
public:
	PelletShooterUprade();
    void applyUpgrade(Player& player) override;
    std::string getName() const override;
};