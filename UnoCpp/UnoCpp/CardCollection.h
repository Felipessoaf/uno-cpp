#pragma once
#include <memory>
#include <vector>

class Card;

class CardCollection
{
public:
    std::shared_ptr<std::vector<std::shared_ptr<Card>>> Cards;

    void AddCard();
    void RemoveCard();
};
