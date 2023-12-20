#include "NumberCard.h"

#include <iostream>

void NumberCard::Action()
{
}

std::string NumberCard::GetName() const
{
    return std::to_string(Number);
}
