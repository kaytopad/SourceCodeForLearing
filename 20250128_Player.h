#pragma once

#include <vector>
#include <string>
#include "20250128_Card.h"

class Player {
protected:
    std::string name;
    std::vector<Card> playerCards;     // 手札
    std::vector<Card> collectedCards; // 獲得したカード

public:
    Player(const std::string& name);
    virtual ~Player() = default;

    void addCard(const Card& card); // 手札にカードを追加
    void collectCard(const Card& card); // 獲得カードに追加
    int getTotalScore() const; // 獲得したカードの合計スコア
    const std::string& getName() const;
    void showHand() const; // 手札を表示
    int getHandSize() const;

    virtual Card playCard() = 0; // 手札からカードを出す（純粋仮想関数）
};
