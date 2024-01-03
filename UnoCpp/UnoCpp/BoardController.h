#pragma once
#include <memory>
#include <vector>

#include "ColorType.h"
#include "Player.h"

class Card;
class CardCollection;

class BoardController
{
public:
    void Setup(const std::shared_ptr<std::vector<Player>>& players);
    void FlipCard();
    void PrintDiscardTop() const;
    bool IsValidMove(const std::weak_ptr<Card>& card) const;
    void PlayCard(const std::shared_ptr<Card>& card);
    bool IsMatchOver() const;

private:
    void CreateCards();
    void CreateNumberCard(int number, ColorType color, int amount) const;
    void CreateEffectCards(ColorType color) const;
    void DistributeCards(const std::shared_ptr<std::vector<Player>>& players) const;
    void ResetDeck();
    
    std::shared_ptr<CardCollection> Deck;
    std::shared_ptr<CardCollection> DiscardPile;
};
