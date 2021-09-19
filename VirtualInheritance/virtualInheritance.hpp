#pragma once

#include "firstChild.hpp"
#include "secondChild.hpp"

#include <assert.h>

class VirtualInheritance : public FirstChild, public SecondChild
{

public:

    VirtualInheritance()
    {
        assert(FirstChild::getValue() == FirstChild::m_firstValue);
        assert(SecondChild::getValue() == SecondChild::m_secondValue);
        assert(FirstChild::m_value == SecondChild::m_value);
    }

private:

    int getValue() const override
    {
        return 0;
    }

};
