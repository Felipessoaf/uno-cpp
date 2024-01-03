#include "Card.h"

#include <vector>

#include "ConsoleIO.h"

void Card::Print() const
{
    ConsoleIO::LogMessage(GetPrintableCard(-1));
}

std::vector<std::string> Card::GetPrintableCard(int index = -1) const
{
    std::vector<std::string> card{};
    card.emplace_back(GetColorId(Color) + (index >= 0 ? "|====" + std::to_string(index) + "=====|" : "|==========|"));
    card.emplace_back(GetPrintableLine("", "|", 10));    
    card.emplace_back(GetPrintableLine(GetName(), "|", 10));
    card.emplace_back(GetPrintableLine(ColorToString(Color), "|", 10));
    card.emplace_back(GetPrintableLine("", "|", 10));
    card.emplace_back(GetColorId(Color) + "|==========|");
    card.emplace_back(GetColorId(None));
    return card;
}

std::string Card::GetPrintableLine(const std::string& textInMiddle, const std::string& symbol, const int lineSize) const
{
    std::string line{GetColorId(Color)};
    const size_t leftPadding = (lineSize - textInMiddle.length()) / 2;
    line += symbol;
    for (size_t i = 0; i < leftPadding; i++)
    {
        line += " ";
    }
    line += textInMiddle;
    const size_t rightPadding = lineSize - textInMiddle.length() - leftPadding;
    for (size_t i = 0; i < rightPadding; i++)
    {
        line += " ";
    }
    line += symbol;
    return line;
}

std::string Card::ColorToString(ColorType color)
{
    switch (color)
    {
    case None:
        throw std::invalid_argument("Invalid Color");
    case Blue:
        return "Blue";
    case Red:
        return "Red";
    case Yellow:
        return "Yellow";
    case Green:
        return "Green";
    default:
        throw std::invalid_argument("Invalid Color");
    }
}

std::string Card::GetColorId(ColorType color)
{
    switch (color)
    {
    case None:
        return "\033[39m";
    case Blue:
        return "\033[34m";
    case Red:
        return "\033[31m";
    case Yellow:
        return "\033[33m";
    case Green:
        return "\033[32m";
    default:
        throw std::invalid_argument("Invalid Color");
    }
}