#pragma once
#include "Card.h"

class NumberCard : public Card
{
public:
    explicit NumberCard(const ColorType color, const int number)
        : Card(color),
          Number(number)
    {
    }

    void Action() override;
    std::string GetName() const override;

private:
    int Number;
};
