#include "JumpCard.h"

#include "ICardEffectHandler.h"

JumpCard::JumpCard(ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler): Card(color, std::move(cardEffectHandler))
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
