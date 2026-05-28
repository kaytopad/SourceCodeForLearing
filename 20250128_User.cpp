#include "20250128_User.h"
#include <iostream>

User::User(const std::string& name) : Player(name) {}

Card User::playCard() {
    int choice;
    while (true) {
        std::cout << "Select a card index (1 to " << getHandSize() << "): ";
        std::cin >> choice;
        if (choice >= 1 && choice <= getHandSize()) {
            Card selectedCard = playerCards[choice - 1];
            playerCards.erase(playerCards.begin() + (choice - 1));
            return selectedCard;
        }
        std::cout << "Invalid choice. Try again." << std::endl;
    }
}
