#pragma once

class Card {
private:
    int value; // カードの値
public:
    Card(int value);
    int getValue() const;
};
