#pragma once
#include "Card.h"

class JumpCard : public Card
{
public:
    explicit JumpCard(ColorType color)
        : Card(color)
    {
    }

    void Action() override;
    std::string GetName() const override;
};
