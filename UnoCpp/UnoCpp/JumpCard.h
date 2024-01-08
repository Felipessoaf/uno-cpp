#pragma once
#include "Card.h"

class JumpCard : public Card
{
public:
    explicit JumpCard(ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler);

    void Action() override;
    std::string GetName() const override;
};
