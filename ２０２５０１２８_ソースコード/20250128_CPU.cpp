#include "20250128_CPU.h"
#include <cstdlib>

CPU::CPU(const std::string& name) : Player(name) {}

Card CPU::playCard() {
    int index = std::rand() % playerCards.size(); // ランダムにインデックスを選択
    Card selectedCard = playerCards[index];
    playerCards.erase(playerCards.begin() + index);
    return selectedCard;
}
