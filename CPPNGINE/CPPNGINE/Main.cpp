#include "CastOperator.h"
#include "CastOperator.hxx"
#include "InitializationLists.h"
#include "Simd.h"
#include "VariadiqueTemplate.h"
#include "VariadiqueTemplate.hxx"

#include "Generic.hxx"
#include <iostream>

int main()
{
	InitializationLists::launchTest();
	Simd::launchTest();
	CastOperator::launchTest();
	VariadiqueTemplate<void()>::launchTest();

	getchar();

	return 0;
}