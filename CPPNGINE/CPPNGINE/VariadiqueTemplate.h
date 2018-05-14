#pragma once

#include "Commun.h"

/*
	this class test variadiques templates

	test with function pointer
*/
template<class F>
class VariadiqueTemplate;

template< class F, class... A >
class VariadiqueTemplate< F(A...) > : Commun
{

public:

	static void launchTest();

public:

	VariadiqueTemplate(F(A...));

	F operator() (A... _args);

private:

	F(*m_fun)(A...);

};