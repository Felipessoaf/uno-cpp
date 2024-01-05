#include "SwitchHandCard.h"

#include "ICardEffectHandler.h"

SwitchHandCard::SwitchHandCard(ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler) : Card(color, std::move(cardEffectHandler))
{
}

void SwitchHandCard::Action()
{
    CardEffectHandler->ToggleDirection();
}

std::string SwitchHandCard::GetName() const
{
    return "Switch";
}
