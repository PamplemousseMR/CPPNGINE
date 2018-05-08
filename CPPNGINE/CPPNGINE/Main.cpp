#include "InitializationLists.h"
/*#include "CastOperator.h"
#include "CastOperator.hxx"*/
#include "Simd.h"
#include "VariadiqueTemplate.h"
#include "VariadiqueTemplate.hxx"

#include "Generic.hxx"
#include <iostream>

double f(int _i, float _f)
{
	return _i + _f;
}

int main()
{
	InitializationListsTest();
	//CastOperatorTest();
	SimdTest();
	//VariadiqueTemplateTest();

	std::cout << "--- VariadiqueTemplateTest ---" << std::endl;
	VariadiqueTemplate<double(int, float)> t(f);
	std::cout << "main " << t(1, 3.f) << std::endl;

	print<float>(1.2f);

	getchar();

	return 0;
}