#pragma once

#include <string>

/*
	this class cast operator

	cast operator
*/
template<typename T>
class CastOperator
{

public:

    CastOperator(const T&);

    operator int() const;

    using arr_t = T[3];
    operator const arr_t*() const
    {
        return &m_arr;
    }

private:

    const T& m_ref;
    const arr_t m_arr;

};
