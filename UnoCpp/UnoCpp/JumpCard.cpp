#include "JumpCard.h"

#include "ICardEffectHandler.h"

JumpCard::JumpCard(ColorType color, ICardEffectHandler* cardEffectHandler) : Card(color, cardEffectHandler)
{
}

void JumpCard::Action()
{
    CardEffectHandler->AddSkipPlayerAmount(1);
}

std::string JumpCard::GetName() const
{
    return "Jump";
}
