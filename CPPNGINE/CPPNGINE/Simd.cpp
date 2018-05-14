#include "Simd.h"

#include <iostream>


void Simd::launchTest()
{
	Commun::test(typeid(Simd).name());
	Simd simd;
	simd.mmintrin();
	simd.xmmintrin();
}