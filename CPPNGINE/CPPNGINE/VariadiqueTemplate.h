#pragma once

#include <vector>

template<class F>
class VariadiqueTemplate;

template< class F, class... A >
class VariadiqueTemplate< F(A...) >
{

public:

	VariadiqueTemplate(F(A...));

	F operator() (A... _args);

private:

	F(*m_fun)(A...);

};

//void VariadiqueTemplateTest();