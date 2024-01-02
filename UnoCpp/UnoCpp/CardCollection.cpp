#include "CardCollection.h"

void CardCollection::AddCard(const std::shared_ptr<Card>& card)
{
    Cards.emplace_back(card);
}

std::shared_ptr<Card> CardCollection::RemoveCard()
{
    std::shared_ptr<Card> card = Cards.at(Cards.size() - 1);
    Cards.pop_back();
    return card;
}
