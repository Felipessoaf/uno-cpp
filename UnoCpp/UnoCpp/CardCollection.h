#pragma once
#include <memory>
#include <vector>

class Card;

class CardCollection
{
    std::vector<std::shared_ptr<Card>> Cards{};
    
public:
    void AddCard(const std::shared_ptr<Card>& card);
    std::shared_ptr<Card> RemoveAt(uint32_t index);
    std::weak_ptr<Card> GetAtTop() const;
    std::weak_ptr<Card> GetAt(uint32_t index) const;
    void Print() const;
    bool IsEmpty() const;
};
