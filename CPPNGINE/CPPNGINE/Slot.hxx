#include "Slot.h"

template< class F, class... A >
Slot< F(A...)>::Slot(F(*_fun)(A...))
{
	m_function = _fun;
}

template< class F, class... A >
F Slot< F(A...) >::call(A... _args)
{
	return m_function(_args...);
}