#include "BoardController.h"

#include <memory>

#include "Card.h"
#include "CardCollection.h"
#include "ForceBuyCard.h"
#include "JumpCard.h"
#include "ConsoleIO.h"
#include "GameConstants.h"
#include "NumberCard.h"
#include "ReverseCard.h"

void BoardController::Setup(const std::shared_ptr<std::vector<Player>>& players)
{
    CreateCards();
    DistributeCards(players);
}

void BoardController::FlipCard()
{
    if (Deck->IsEmpty())
    {
        ResetDeck();
    }
    DiscardPile->AddCard(Deck->RemoveCard());
}

void BoardController::PrintDiscardTop()
{
    // DiscardPile.
}

void BoardController::CheckValidMove(std::shared_ptr<Card> card)
{
}

void BoardController::CreateCards()
{
    Deck = std::make_shared<CardCollection>();
    DiscardPile = std::make_shared<CardCollection>();

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

void BoardController::DistributeCards(const std::shared_ptr<std::vector<Player>>& players) const
{
    for (int i = 0; i < GameConstants::CARDS_START_NUMBER; ++i)
    {
        for (Player& player : *players)
        {
            player.Cards.AddCard(Deck->RemoveCard());
        }
    }
}

void BoardController::ResetDeck()
{
}
