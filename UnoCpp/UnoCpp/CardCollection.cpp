#include "CardCollection.h"

#include <string>

#include "Card.h"
#include "ConsoleIO.h"

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

void CardCollection::Print()
{
    std::vector<std::string> lines{};
    const std::string cardPadding = "      ";
    for (const std::shared_ptr<Card>& card : Cards)
    {
        std::vector<std::string> printableCard = card->GetPrintableCard();
        for (size_t i = 0; i < printableCard.size(); ++i)
        {
            if (lines.size() <= i)
            {
                lines.emplace_back(printableCard[i] + cardPadding);
            }
            else
            {
                lines[i].append(printableCard[i] + cardPadding);
            }
        }
    }
    ConsoleIO::LogMessage(lines);
}

bool CardCollection::IsEmpty() const
{
    return Cards.empty();
}
