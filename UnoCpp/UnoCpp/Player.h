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

    void PlayTurn();
    void Print();

private:
    std::shared_ptr<BoardController> boardController;
};
