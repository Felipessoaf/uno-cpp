#include "Player.h"

#include <utility>

#include "BoardController.h"
#include "ConsoleIO.h"

Player::Player(std::string name, std::shared_ptr<BoardController> board)
    : Name(std::move(name)), boardController(std::move(board))
{
}

bool Player::PlayTurn()
{
    hasShoutedUno = false;
    // TODO: if there's only 2 cards left, show the option to yell "UNO!"

    std::weak_ptr<Card> card{};
    int cardIndex;
    do
    {
        cardIndex = ConsoleIO::GetInput<int>("Choose a valid card to play (starting at index 0) or -1 if there's no valid card:\n");

        if (cardIndex == -1)
        {
            return false;
        }
        
        card = Cards.LookAt(cardIndex);
    }
    while (card.expired() || !boardController->IsValidMove(card));

    boardController->PlayCard(Cards.RemoveAt(cardIndex));
    
    return true;
}

void Player::Print() const
{
    Cards.Print(true);
}

void Player::BuyCard(int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        Cards.AddCard(boardController->GetDeckTopCard());   
    }
}

bool Player::HasShoutedUno() const
{
    return hasShoutedUno;
}

size_t Player::GetAmountOfCards() const
{
    return Cards.GetAmount();
}
