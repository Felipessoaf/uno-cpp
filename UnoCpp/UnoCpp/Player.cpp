#include "Player.h"

#include <utility>

#include "BoardController.h"
#include "ConsoleIO.h"

Player::Player(std::string name, std::shared_ptr<BoardController> board)
    : Name(std::move(name)), boardController(std::move(board))
{
}

void Player::PlayTurn()
{
    // TODO: if there's only 2 cards left, show the option to yell "UNO!"
    
    int cardIndex = ConsoleIO::GetInput<int>("Choose a card to play (starting at index 0)");
    std::weak_ptr<Card> card = Cards.GetAt(cardIndex);
    if (card.expired())
    {
        ConsoleIO::LogMessage("Invalid card index\n");
        PlayTurn();
        return;
    }
    
    if (!boardController->IsValidMove(card))
    {
        ConsoleIO::LogMessage("Invalid move\n");
        PlayTurn();
        return;
    }

    boardController->PlayCard(Cards.RemoveAt(cardIndex));
}

void Player::Print()
{
    ConsoleIO::LogMessage(Name + "\n");
    Cards.Print();
}
