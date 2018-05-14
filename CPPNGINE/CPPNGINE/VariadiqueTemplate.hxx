#include "VariadiqueTemplate.h"

#include <iostream>

template<class F, class... A>
void VariadiqueTemplate< F(A...) >::launchTest()
{
	Commun::test(typeid(VariadiqueTemplate).name());
	VariadiqueTemplate<double(int, float)> t([] -> double (int _i, float _f) {
		return _i + _f;
	});
	std::cout << t(1, 3.f) << std::endl;
}

template<class F, class... A>
VariadiqueTemplate< F(A...) >::VariadiqueTemplate(F(*_fun)(A...))
	:	m_fun(_fun)
{
	std::cout << "cons " << _fun(1, 3.f) << std::endl;
}

template<class F, class... A>
F VariadiqueTemplate< F(A...) >::operator() (A... _args)
{
	std::cout << "op " << m_fun(1, 3.f) << std::endl;
	std::cout << "op " << m_fun(_args...) << std::endl;
	return m_fun(_args...);
}