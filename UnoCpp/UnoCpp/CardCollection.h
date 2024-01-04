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
    std::weak_ptr<Card> LookAtTop() const;
    std::weak_ptr<Card> LookAt(size_t index) const;
    void Print(bool includeIndex) const;
    bool IsEmpty() const;
    void Shuffle();
    size_t GetAmount() const;
};
