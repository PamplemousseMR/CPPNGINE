#include "CastOperator.h"

#include <iostream>

void CastOperator::launchTest()
{
	Commun::test(typeid(CastOperator).name());
	CastOperator co("test");
	int size = co.operator int();
	std::cout << "size => " << size << std::endl;
}

CastOperator::CastOperator(const std::string& _str)
	:	m_str(_str)
{
}

CastOperator::operator int() const
{
	return m_str.size();
}