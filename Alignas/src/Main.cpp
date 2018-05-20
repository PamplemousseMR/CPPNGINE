#include "Alignas.h"

#include <assert.h>

/*
    this project test alignas keyword, _declspec(align(x)), __attribute__ (aligned(x))

    alignment is based on the size of maximum member of the struct, but it could be change
    by alignas
*/
int main()
{
    assert(alignof(A) == 8);
    assert(sizeof(A) == 16);
    assert(alignof(B) == 4);
    assert(sizeof(B) == 8);
    assert(alignof(C) == 1);
    assert(sizeof(C) == 2);
    assert(alignof(D) == 8);
    assert(sizeof(D) == 40);
    assert(alignof(E) == 8);
    assert(sizeof(E) == 24);
    assert(alignof(F) == 8);
    assert(sizeof(F) == 24);
    assert(alignof(AAligned) == 16);
    assert(sizeof(AAligned) == 32);

    return 0;
}
