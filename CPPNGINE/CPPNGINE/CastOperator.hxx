#include "CastOperator.h"

template<class T>
CastOperator<T>::CastOperator(T& _ref)
	:	m_ref(&_ref)
{
}

template< typename T >
CastOperator<T>::operator T&() const
{
	return *m_ref;
}

template< typename T >
CastOperator<T>::operator const T&() const
{
	return *m_ref;
}