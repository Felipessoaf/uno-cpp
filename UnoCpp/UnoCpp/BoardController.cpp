#include "BoardController.h"

#include <memory>

#include "Card.h"
#include "CardCollection.h"
#include "ForceBuyCard.h"
#include "JumpCard.h"
#include "Logger.h"
#include "NumberCard.h"
#include "ReverseCard.h"

void BoardController::Setup(std::shared_ptr<std::vector<Player>> players)
{
    CreateCards();
    DistributeCards(players);
}

void BoardController::CreateCards()
{
    Deck = std::make_shared<CardCollection>();

    for (int i = 0; i < 10; ++i)
    {
        CreateNumberCard(i, Blue, 2);
        CreateNumberCard(i, Red, 2);
        CreateNumberCard(i, Yellow, 2);
        CreateNumberCard(i, Green, 2);
    }
    CreateEffectCards(Blue);
    CreateEffectCards(Red);
    CreateEffectCards(Yellow);
    CreateEffectCards(Green);

#ifdef _DEBUG
    std::vector<std::string> lines{};
    const std::string cardPadding = "      ";
    for (const std::shared_ptr<Card>& card : Deck->Cards)
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
    Logger::LogMessage(lines);
    Logger::LogMessage("End Cards");
#endif
}

void BoardController::CreateNumberCard(int number, ColorType color, const int amount) const
{
    for (int i = 0; i < amount; ++i)
    {
        const std::shared_ptr<Card> card = std::static_pointer_cast<Card>(std::make_shared<NumberCard>(color, number));
        Deck->AddCard(card);   
    }
}

void BoardController::CreateEffectCards(ColorType color) const
{
    for (int i = 0; i < 2; ++i)
    {
        Deck->AddCard(std::static_pointer_cast<Card>(std::make_shared<ForceBuyCard>(color, 2)));
        Deck->AddCard(std::static_pointer_cast<Card>(std::make_shared<ReverseCard>(color)));
        Deck->AddCard(std::static_pointer_cast<Card>(std::make_shared<JumpCard>(color)));
    }
}

void BoardController::DistributeCards(std::shared_ptr<std::vector<Player>> players)
{
}

void BoardController::Print(std::shared_ptr<std::vector<Player>> players)
{
}

void BoardController::CheckValidMove(std::shared_ptr<Card> card)
{
}

void BoardController::ResetDeck()
{
}
