#include "Simd.h"

#include <iostream>

void SimdTest()
{
	std::cout << "--- SimdTest ---" << std::endl;
	mmintrin();
	xmmintrin();
}