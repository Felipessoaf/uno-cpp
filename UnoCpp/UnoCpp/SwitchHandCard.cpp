#include "SwitchHandCard.h"

#include "ConsoleIO.h"
#include "ICardEffectHandler.h"

SwitchHandCard::SwitchHandCard(ColorType color, ICardEffectHandler* cardEffectHandler) : Card(color, cardEffectHandler)
{
}

void SwitchHandCard::Action()
{
    int playerIndex;
    do
    {
        playerIndex = ConsoleIO::GetInput<int>("Choose the player's index to switch hands:\n");
    }
    while (!CardEffectHandler->SwitchHand(playerIndex));
}

std::string SwitchHandCard::GetName() const
{
    return "Switch";
}
