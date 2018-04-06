#include "Ref.h"

template< typename T >
Ref<T>::Ref(T& _ref)
	: m_ref(&_ref)
{
}

template< typename T >
Ref<T>::operator T&() const
{
	return *m_ref;
}

template< typename T >
Ref<T>::operator const T&() const
{
	return *m_ref;
}