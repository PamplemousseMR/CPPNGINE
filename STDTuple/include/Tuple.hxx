#include "Tuple.h"

Tuple<>::Tuple()
{

}

std::ostream& Tuple<>::operator <<(std::ostream& _o) const
{
    return _o;
}

template<class T, class... R>
Tuple<T, R...>::Tuple(T _this, R... _rest)
    :   Tuple<R...>(_rest...),
        m_this(_this)
{

}

template<class T, class... R>
std::ostream&  Tuple<T, R...>::operator <<(std::ostream& _o) const
{
    _o << m_this << " ";
    return Tuple<R...>::operator <<(_o);
}
