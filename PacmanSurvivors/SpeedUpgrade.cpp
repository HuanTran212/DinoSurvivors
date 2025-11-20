#include "SpeedUpgrade.h"
#include "Player.h"

SpeedUpgrade::SpeedUpgrade() {
    // Hàm dựng rỗng
}

void SpeedUpgrade::applyUpgrade(Player& player)
{
    // Tăng tốc độ thêm 15 (khoảng 15%)
    player.addMoveSpeed(15.f);
}

std::string SpeedUpgrade::getName() const
{
    return "Tang Toc Do Di Chuyen";
}