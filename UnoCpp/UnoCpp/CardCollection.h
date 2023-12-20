#pragma once
#include <memory>
#include <vector>

class Card;

class CardCollection
{
public:
    std::vector<std::shared_ptr<Card>> Cards{};

    void AddCard(const std::shared_ptr<Card>& card);
    void RemoveCard();
};
