#include "CardCollection.h"

void CardCollection::AddCard(const std::shared_ptr<Card>& card)
{
    Cards.emplace_back(card);
}

void CardCollection::RemoveCard()
{
}
