#pragma once
#include <memory>
#include <string>

class CardCollection;

class Player
{
public:
    std::string Name;
    std::shared_ptr<CardCollection> Cards;

    void PlayTurn();
    void Print();
};
