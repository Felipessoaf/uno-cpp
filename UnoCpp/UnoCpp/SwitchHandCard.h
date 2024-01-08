#pragma once

#include "Card.h"

class SwitchHandCard: public Card
{
public:
    explicit SwitchHandCard(ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler);

    void Action() override;
    std::string GetName() const override;
};
