#include "NumberCard.h"

#include <iostream>
#include <utility>

NumberCard::NumberCard(const ColorType color, const int number, ICardEffectHandler* cardEffectHandler)
    : Card(color, cardEffectHandler), Number(number)
{
}

void NumberCard::Action()
{
}

std::string NumberCard::GetName() const
{
    return std::to_string(Number);
}
