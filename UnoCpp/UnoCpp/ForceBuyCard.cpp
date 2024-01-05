#include "ForceBuyCard.h"

#include "ICardEffectHandler.h"

ForceBuyCard::ForceBuyCard(ColorType color, int amount, std::shared_ptr<ICardEffectHandler> cardEffectHandler)
    : Card(color, std::move(cardEffectHandler)), Amount(amount)
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
