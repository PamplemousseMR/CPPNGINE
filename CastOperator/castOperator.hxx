#include "CastOperator.hpp"

template<typename T>
CastOperator<T>::CastOperator(const T& _ref)
    :	m_ref(_ref),
        m_arr{_ref, _ref, _ref}
{
}

template<typename T>
CastOperator<T>::operator int() const
{
    return static_cast<int>(sizeof(m_ref));
}

/*template<typename T>
CastOperator<T>::operator const arr_t*() const
{
    return &m_arr;
}*/
