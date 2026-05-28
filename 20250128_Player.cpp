#include "20250128_Player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name) {}

void Player::addCard(const Card& card) {
    playerCards.push_back(card);
}

void Player::collectCard(const Card& card) {
    collectedCards.push_back(card);
}

int Player::getTotalScore() const {
    int total = 0;
    for (const Card& card : collectedCards) {
        total += card.getValue();
    }
    return total;
}

const std::string& Player::getName() const {
    return name;
}

void Player::showHand() const {
    std::cout << name << "'s Hand: ";
    for (size_t i = 0; i < playerCards.size(); ++i) {
        std::cout << "[" << i + 1 << ":" << playerCards[i].getValue() << "] ";
    }
    std::cout << std::endl;
}

int Player::getHandSize() const {
    return playerCards.size();
}