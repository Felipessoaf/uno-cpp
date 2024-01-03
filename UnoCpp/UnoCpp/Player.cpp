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

    std::weak_ptr<Card> card{};
    int cardIndex;
    do
    {
        cardIndex = ConsoleIO::GetInput<int>("Choose a valid card to play (starting at index 0):\n");
        card = Cards.GetAt(cardIndex);
    }
    while (card.expired() || !boardController->IsValidMove(card));

    boardController->PlayCard(Cards.RemoveAt(cardIndex));
}

void Player::Print() const
{
    ConsoleIO::LogMessage(Name + "\n");
    Cards.Print();
}
