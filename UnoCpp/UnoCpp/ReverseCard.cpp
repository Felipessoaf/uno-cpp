#include "ReverseCard.h"

#include "ICardEffectHandler.h"

ReverseCard::ReverseCard(ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler)
    : Card(color, std::move(cardEffectHandler))
{
}

void ReverseCard::Action()
{
    CardEffectHandler->ToggleDirection();
}

std::string ReverseCard::GetName() const
{
    return "Reverse";
}
