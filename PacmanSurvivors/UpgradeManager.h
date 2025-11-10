#pragma once
#include <SFML/Graphics.hpp>
#include "IUpgrade.h"
#include <vector>
#include <memory>

class UpgradeManager {
public:
	static UpgradeManager& getInstance();
	std::vector<IUpgrade*> getRandomUpgrades(int count);

private:
	UpgradeManager();
	~UpgradeManager() = default;
	UpgradeManager(const UpgradeManager&) = delete;
	UpgradeManager& operator=(const UpgradeManager&) = delete;

	std::vector<std::unique_ptr<IUpgrade>> m_upgradePool;
};