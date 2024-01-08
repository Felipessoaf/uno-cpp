#include "SwitchHandCard.h"

#include "ConsoleIO.h"
#include "ICardEffectHandler.h"

SwitchHandCard::SwitchHandCard(ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler) : Card(color, std::move(cardEffectHandler))
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
