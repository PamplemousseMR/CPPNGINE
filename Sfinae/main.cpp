#include "sfinae.hpp"

#include <assert.h>
#include <string>
#include <xmmintrin.h>

/*
    this project test SFINAE
*/
int main()
{
    assert( (HasStreamOperatorPtr<std::ostream, std::string>::value) );
    assert( !(HasStreamOperatorPtr<std::ostream, __m128>::value) );
    assert( (HasStreamOperatorDecltypePtr<std::ostream, std::string>::value) );
    assert( !(HasStreamOperatorDecltypePtr<std::ostream, __m128>::value) );
    assert( (HasStreamOperatorDecltypeDeclvalPtr<std::ostream, std::string>::value) );
    assert( !(HasStreamOperatorDecltypeDeclvalPtr<std::ostream, __m128>::value) );

    __m128 a;
    assert(CanPrint::print("test"));
    assert(!CanPrint::print(a));

    return 0;
}
