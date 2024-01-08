#include "ForceBuyCard.h"

#include "ICardEffectHandler.h"

ForceBuyCard::ForceBuyCard(ColorType color, int amount, ICardEffectHandler* cardEffectHandler)
    : Card(color, cardEffectHandler), Amount(amount)
{
}

void ForceBuyCard::Action()
{
    CardEffectHandler->AddBuyCardsAmount(Amount);
}

std::string ForceBuyCard::GetName() const
{
    return "+" + std::to_string(Amount);
}
