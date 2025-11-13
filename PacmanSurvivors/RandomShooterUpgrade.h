#pragma once
#include "IUpgrade.h"

class RandomShooterUpgrade : public IUpgrade
{
public:
    RandomShooterUpgrade();

    void applyUpgrade(Player& player) override;
    std::string getName() const override;
};
