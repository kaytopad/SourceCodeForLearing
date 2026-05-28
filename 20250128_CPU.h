#pragma once

#include"20250128_Player.h"

class CPU : public Player {
public:
    CPU(const std::string& name);
    Card playCard() override; // ランダムでカードを選ぶ
};
