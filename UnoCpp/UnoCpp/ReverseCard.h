#pragma once
#include "Card.h"

class ReverseCard : public Card
{
public:
    explicit ReverseCard(ColorType color)
        : Card(color)
    {
    }

    void Action() override;
    std::string GetName() const override;
};
