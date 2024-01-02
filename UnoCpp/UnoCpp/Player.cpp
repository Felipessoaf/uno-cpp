#include "Player.h"

#include "ConsoleIO.h"

Player::Player(std::string name)
    : Name(std::move(name))
{
}

void Player::PlayTurn()
{
    // TODO: if there's only 2 cards left, show the option to yell "UNO!" 
    int cardIndex = ConsoleIO::GetInput<int>("Choose a card to play (starting at index 0)");
    
}

void Player::Print()
{
    ConsoleIO::LogMessage(Name + "\n");
    Cards.Print();
}
