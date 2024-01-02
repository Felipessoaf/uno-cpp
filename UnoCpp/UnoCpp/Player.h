#pragma once
#include <string>

#include "CardCollection.h"

class Player
{
public:
    Player(std::string name);
    
    std::string Name;
    CardCollection Cards;

    void PlayTurn();
    void Print();
};
