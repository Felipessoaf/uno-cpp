#pragma once
#include "Card.h"

class ForceBuyCard : public Card
{
public:
    explicit ForceBuyCard(ColorType color, int amount, ICardEffectHandler* cardEffectHandler);

    void Action() override;
    std::string GetName() const override;

    int Amount;
};
