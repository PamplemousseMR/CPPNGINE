#pragma once

class Root
{

public:

    Root()
    {
    }

protected:

    virtual int getValue() const
    {
        return m_value;
    }

protected:

    const int m_value = 12;

};
