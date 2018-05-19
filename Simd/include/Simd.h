#pragma once

#ifdef __unix__
#define aligned32 __attribute__ ((aligned(32)))
#else
#define aligned32 _declspec(align(32))
#endif

void mmintrin();
void xmmintrin();
