#pragma once
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ColorType.h"

class ICardEffectHandler;

class Card
{
public:
    explicit Card(const ColorType color, std::shared_ptr<ICardEffectHandler> cardEffectHandler) : Color {color}, CardEffectHandler(
        std::move(cardEffectHandler))
    {
        
    }
    virtual ~Card() = default;
    ColorType Color;

    virtual void Action() = 0;
    virtual std::string GetName() const = 0;

    void Print() const;
    std::vector<std::string> GetPrintableCard(int index) const;
    std::string GetPrintableLine(const std::string& textInMiddle, const std::string& symbol, int lineSize) const;

protected:    
    std::shared_ptr<ICardEffectHandler> CardEffectHandler;

private:
    static std::string ColorToString(ColorType color);
    static std::string GetColorId(ColorType color);
};
