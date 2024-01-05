#pragma once

class ICardEffectHandler
{
public:
    virtual ~ICardEffectHandler() = default;
    
    virtual void AddSkipPlayerAmount(int skipAmount) = 0;
    virtual void AddBuyCardsAmount(int buyAmount) = 0;
    virtual void ToggleDirection() = 0;
    virtual void SwitchHand(int playerIndex) = 0;
};
