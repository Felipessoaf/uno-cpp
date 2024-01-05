#include "CardCollection.h"

#include <chrono>
#include <random>
#include <string>

#include "Card.h"
#include "ConsoleIO.h"

void CardCollection::AddCard(const std::shared_ptr<Card>& card)
{
    Cards.emplace_back(card);
}

std::shared_ptr<Card> CardCollection::RemoveAtTop()
{
    return RemoveAt(Cards.size() - 1);
}

std::shared_ptr<Card> CardCollection::RemoveAt(const uint32_t index)
{
    if (index < 0 || index >= Cards.size())
    {
        return {};
    }
    
    std::shared_ptr<Card> card = Cards.at(index);
    Cards.erase(Cards.begin() + index);
    return card;
}

std::weak_ptr<Card> CardCollection::LookAtTop() const
{
    return LookAt(Cards.size() - 1);
}

std::weak_ptr<Card> CardCollection::LookAt(const size_t index) const
{
    if (index < 0 || index >= Cards.size())
    {
        return {};
    }

    return Cards.at(index);
}

void CardCollection::Print(bool includeIndex) const
{
    std::vector<std::string> lines{};
    const std::string cardPadding = "    ";
    for (int j = 0; j < Cards.size(); j++)
    {
        std::vector<std::string> printableCard = Cards.at(j)->GetPrintableCard(includeIndex ? j : -1);
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

void CardCollection::Shuffle()
{
    const unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    auto rng = std::default_random_engine {seed};
    std::ranges::shuffle(Cards, rng);
}

size_t CardCollection::GetAmount() const
{
    return Cards.size();
}

void CardCollection::ClearCards()
{
    Cards.clear();
}

std::vector<std::shared_ptr<Card>> CardCollection::GetCards()
{
    return std::move(Cards);
}

void CardCollection::SetCards(std::vector<std::shared_ptr<Card>> cards)
{
    Cards = std::move(cards);
}
