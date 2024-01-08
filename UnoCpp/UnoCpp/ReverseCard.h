#pragma once
#include "Card.h"

class ReverseCard : public Card
{
public:
    explicit ReverseCard(ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler);

    void Action() override;
    std::string GetName() const override;
};
