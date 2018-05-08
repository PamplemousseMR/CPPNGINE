#pragma once

#ifdef __unix__
#define aligned __attribute__ ((aligned(32)))
#else
#define aligned _declspec(align(32))
#endif