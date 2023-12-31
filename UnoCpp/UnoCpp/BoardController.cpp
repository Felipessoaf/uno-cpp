#include "BoardController.h"

#include <memory>
#include <utility>

#include "Card.h"
#include "CardCollection.h"
#include "ForceBuyCard.h"
#include "JumpCard.h"
#include "GameConstants.h"
#include "NumberCard.h"
#include "ReverseCard.h"
#include "SwitchHandCard.h"

void BoardController::Setup(const std::shared_ptr<std::vector<Player>>& players, std::shared_ptr<ICardEffectHandler> cardEffectHandler)
{
    CardEffectHandler = std::move(cardEffectHandler);
    CreateCards();
    DistributeCards(players);
}

void BoardController::FlipCard()
{
    if (Deck->IsEmpty())
    {
        ResetDeck();
    }
    DiscardPile->AddCard(Deck->RemoveAt(0));
}

void BoardController::PrintDiscardTop() const
{
    if (const std::weak_ptr<Card> tableCard = DiscardPile->LookAtTop(); !tableCard.expired())
    {
        const std::shared_ptr<Card> card = tableCard.lock();
        card->Print();
    }
}

bool BoardController::IsValidMove(const std::weak_ptr<Card>& card, bool isForceBuyInEffect) const
{
    if (card.expired())
    {
        return false;
    }

    std::shared_ptr<Card> cardToCheck = card.lock();
    std::shared_ptr<Card> cardAtTop = DiscardPile->LookAtTop().lock();

    if (isForceBuyInEffect && cardToCheck->GetName() != cardAtTop->GetName())
    {
        return false;
    }

    if (cardToCheck->Color == Special || cardAtTop->Color == Special)
    {
        return true;
    }
    
    if (cardToCheck->Color != cardAtTop->Color && cardToCheck->GetName() != cardAtTop->GetName())
    {
        return false;
    }
    
    return true;
}

void BoardController::PlayCard(const std::shared_ptr<Card>& card)
{
    card->Action();
    DiscardPile->AddCard(card);
}

std::shared_ptr<Card> BoardController::GetDeckTopCard()
{
    if (Deck->IsEmpty())
    {
        ResetDeck();
    }
    
    return Deck->RemoveAt(0);
}

size_t BoardController::GetDeckAmount() const
{
    return Deck->GetAmount();
}

size_t BoardController::GetDiscardPileAmount() const
{
    return DiscardPile->GetAmount();
}

void BoardController::CreateCards()
{
    Deck = std::make_shared<CardCollection>();
    DiscardPile = std::make_shared<CardCollection>();

    for (int i = 0; i <= GameConstants::CARDS_NUMBER_MAX; ++i)
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
    CreateSpecialEffectCards(Special);

    Deck->Shuffle();
}

void BoardController::CreateNumberCard(int number, ColorType color, const int amount) const
{
    for (int i = 0; i < amount; ++i)
    {
        const std::shared_ptr<Card> card = std::static_pointer_cast<Card>(std::make_shared<NumberCard>(color, number, CardEffectHandler));
        Deck->AddCard(card);   
    }
}

void BoardController::CreateEffectCards(ColorType color) const
{
    for (int i = 0; i < 2; ++i)
    {
        Deck->AddCard(std::static_pointer_cast<Card>(std::make_shared<ForceBuyCard>(color, 2, CardEffectHandler)));
        Deck->AddCard(std::static_pointer_cast<Card>(std::make_shared<ReverseCard>(color, CardEffectHandler)));
        Deck->AddCard(std::static_pointer_cast<Card>(std::make_shared<JumpCard>(color, CardEffectHandler)));
    }
}

void BoardController::CreateSpecialEffectCards(ColorType color) const
{
    for (int i = 0; i < 4; ++i)
    {
        Deck->AddCard(std::static_pointer_cast<Card>(std::make_shared<SwitchHandCard>(color, CardEffectHandler)));
    }
}

void BoardController::DistributeCards(const std::shared_ptr<std::vector<Player>>& players) const
{
    for (int i = 0; i < GameConstants::CARDS_START_NUMBER; ++i)
    {
        for (Player& player : *players)
        {
            player.Cards.AddCard(Deck->RemoveAt(0));
        }
    }
}

void BoardController::ResetDeck()
{
    std::shared_ptr<Card> topCard = DiscardPile->RemoveAtTop();
    std::vector<std::shared_ptr<Card>> discardPile = DiscardPile->GetCards(); 
    std::vector<std::shared_ptr<Card>> deck = Deck->GetCards();
    deck.insert(
      deck.end(),
      std::make_move_iterator(discardPile.begin()),
      std::make_move_iterator(discardPile.end())
    );
    Deck->SetCards(std::move(deck));
    
    DiscardPile->ClearCards();
    DiscardPile->AddCard(topCard);
}
