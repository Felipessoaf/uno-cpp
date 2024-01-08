#pragma once
#include "Card.h"

class JumpCard : public Card
{
public:
    explicit JumpCard(ColorType color, ICardEffectHandler* cardEffectHandler);

    void Action() override;
    std::string GetName() const override;
};
