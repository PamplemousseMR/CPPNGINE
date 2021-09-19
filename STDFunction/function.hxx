#include "function.hpp"

template<class F, class... A>
Function< F(A...) >::Function(F(*_fun)(A...))
	:	m_fun(_fun)
{
    m_arity = sizeof...(A);
}

template<class F, class... A>
F Function< F(A...) >::operator() (A... _args)
{
	return m_fun(_args...);
}
