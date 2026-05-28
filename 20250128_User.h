#pragma once

#include "20250128_Player.h"

class User : public Player {
public:
    User(const std::string& name);
    Card playCard() override; // ユーザーが手札からカードを選ぶ
};
