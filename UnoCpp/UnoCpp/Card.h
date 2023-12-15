#pragma once
#include "ColorType.h"

class Card
{
public:
    virtual ~Card() = default;
    ColorType Color;

    virtual void Action() = 0;
    virtual void Print() = 0;
};
