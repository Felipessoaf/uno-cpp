#include "Player.h"

#include <utility>

#include "BoardController.h"
#include "ConsoleIO.h"

Player::Player(std::string name, std::shared_ptr<BoardController> board)
    : Name(std::move(name)), boardController(std::move(board))
{
}

bool Player::PlayTurn(bool isForceBuyInEffect)
{
    hasShoutedUno = false;
    bool shouldShoutUno = GetAmountOfCards() == 2;

    std::weak_ptr<Card> card{};
    int move;
    do
    {
        std::string msg = "Choose a valid card to play (starting at index 0) or -1 if there's no valid card:\n";
        if(shouldShoutUno)
        {
            msg += "Or -2 to shout UNO!\n";
        }
        move = ConsoleIO::GetInput<int>(msg);

        if (move == -1)
        {
            return false;
        }

        if (move == -2)
        {
            hasShoutedUno = true;
        }
        
        card = Cards.LookAt(move);
    }
    while (card.expired() || !boardController->IsValidMove(card, isForceBuyInEffect));

    boardController->PlayCard(Cards.RemoveAt(move));
    
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
