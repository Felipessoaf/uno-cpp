#pragma once
#include <memory>
#include <vector>

class Card;

class CardCollection
{
    std::vector<std::shared_ptr<Card>> Cards{};
    
public:
    void AddCard(const std::shared_ptr<Card>& card);
    std::shared_ptr<Card> RemoveCard();
};
