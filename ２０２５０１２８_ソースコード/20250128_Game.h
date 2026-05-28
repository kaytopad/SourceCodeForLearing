#pragma once

#include <vector>
#include "20250128_Card.h"
#include "20250128_User.h"
#include "20250128_CPU.h"

class Game {
private:
    std::vector<Card> scoreCards;
    User user;
    CPU cpu;
    void shuffleScoreCards();
    void playRound(int roundIndex);
public:
    Game();
    void playGame();
};
