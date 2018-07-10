#pragma once

#include "Root.hpp"

class SecondChild : virtual public Root
{

public:

    SecondChild()
    {
    }

protected:

    int getValue() const override
    {
        return m_secondValue;
    }

protected:

    const int m_secondValue = 18;

};
