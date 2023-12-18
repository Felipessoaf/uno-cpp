#pragma once
#include <memory>
#include <vector>

#include "Player.h"

class Card;
class CardCollection;

class BoardController
{
public:
    std::shared_ptr<CardCollection> Deck;
    std::shared_ptr<CardCollection> DiscardPile;

    void DistributeCards();
    void Print(std::shared_ptr<std::vector<Player>> players);
    void CheckValidMove(std::shared_ptr<Card> card);
    void ResetDeck();
};
