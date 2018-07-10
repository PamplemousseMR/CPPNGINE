#pragma once

#include "Root.hpp"

class FirstChild : virtual  public Root
{

public:

    FirstChild()
    {
    }

protected:

    int getValue() const override
    {
        return m_firstValue;
    }

protected:

    const int m_firstValue = 15;

};
