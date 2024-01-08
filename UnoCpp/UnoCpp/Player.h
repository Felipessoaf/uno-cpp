#pragma once
#include <string>

#include "CardCollection.h"

class BoardController;

class Player
{
public:
    Player(std::string name, std::shared_ptr<BoardController> board);
    
    std::string Name;
    CardCollection Cards;

    [[nodiscard]] bool PlayTurn(bool isForceBuyInEffect);
    void Print() const;
    void BuyCard(int amount);
    bool HasShoutedUno() const;
    size_t GetAmountOfCards() const;

private:
    std::shared_ptr<BoardController> boardController;
    bool hasShoutedUno;
};
