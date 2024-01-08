#pragma once
#include "Card.h"

class NumberCard : public Card
{
public:
    explicit NumberCard(ColorType color, int number, ICardEffectHandler* cardEffectHandler);

    void Action() override;
    std::string GetName() const override;

private:
    int Number;
};
