#include "NumberCard.h"

#include <iostream>
#include <utility>

NumberCard::NumberCard(const ColorType color, const int number, std::shared_ptr<ICardEffectHandler> cardEffectHandler)
    : Card(color, std::move(cardEffectHandler)), Number(number)
{
}

void NumberCard::Action()
{
}

std::string NumberCard::GetName() const
{
    return std::to_string(Number);
}
