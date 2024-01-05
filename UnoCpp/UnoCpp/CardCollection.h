#pragma once
#include <memory>
#include <vector>

class Card;

class CardCollection
{
    std::vector<std::shared_ptr<Card>> Cards{};
    
public:
    void AddCard(const std::shared_ptr<Card>& card);
    [[nodiscard]] std::shared_ptr<Card> RemoveAtTop();
    [[nodiscard]] std::shared_ptr<Card> RemoveAt(uint32_t index);
    [[nodiscard]] std::weak_ptr<Card> LookAtTop() const;
    [[nodiscard]] std::weak_ptr<Card> LookAt(size_t index) const;
    void Print(bool includeIndex) const;
    [[nodiscard]] bool IsEmpty() const;
    void Shuffle();
    [[nodiscard]] size_t GetAmount() const;
    void ClearCards();
    std::vector<std::shared_ptr<Card>> GetCards();
    void SetCards(std::vector<std::shared_ptr<Card>> cards);
};
