#include "Card.h"

#include "Logger.h"

void Card::Print() const
{
    std::string card{};
    card += GetColorId(Color);
    card += "|==========|\n";
    card += PrintCardLine("", "|", 10);
    card += PrintCardLine(GetName(), "|", 10);
    card += PrintCardLine(ColorToString(Color), "|", 10);
    card += PrintCardLine("", "|", 10);
    card += "|==========|\n";
    card += GetColorId(None);
    Logger::LogMessage(card);
}

std::string Card::PrintCardLine(const std::string& textInMiddle, const std::string& symbol, const int lineSize)
{
    std::string line{};
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
    line += "\n";
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