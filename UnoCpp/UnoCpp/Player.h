#pragma once
#include <string>

#include "CardCollection.h"

class Player
{
public:
    std::string Name;
    CardCollection Cards;

    void PlayTurn();
    void Print();
};
