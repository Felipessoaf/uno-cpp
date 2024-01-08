#include "ReverseCard.h"

#include "ICardEffectHandler.h"

ReverseCard::ReverseCard(ColorType color, ICardEffectHandler* cardEffectHandler)
    : Card(color, cardEffectHandler)
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
