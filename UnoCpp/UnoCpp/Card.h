#pragma once
#include <string>
#include <vector>

#include "ColorType.h"

class Card
{
public:
    explicit Card(const ColorType color) : Color {color}
    {
        
    }
    virtual ~Card() = default;
    ColorType Color;

    virtual void Action() = 0;

    void Print() const;
    std::vector<std::string> GetPrintableCard() const;
    std::string GetPrintableLine(const std::string& textInMiddle, const std::string& symbol, int lineSize) const;

private:
    virtual std::string GetName() const = 0;
    static std::string ColorToString(ColorType color);
    static std::string GetColorId(ColorType color);
};
