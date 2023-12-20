#include "ForceBuyCard.h"

void ForceBuyCard::Action()
{
}

std::string ForceBuyCard::GetName() const
{
    return "+" + std::to_string(Amount);
}
