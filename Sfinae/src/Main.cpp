#include "Sfinae.h"

#include <assert.h>
#include <string>
#include <xmmintrin.h>

/*
    this project test SFINAE
*/
int main()
{
    assert( (HasStreamOperator<std::ostream, std::string>::value) );
    assert( !(HasStreamOperator<std::ostream, __m128>::value) );
    assert( (HasStreamOperatorDecltype<std::ostream, std::string>::value) );
    assert( !(HasStreamOperatorDecltype<std::ostream, __m128>::value) );

    __m128 a;
    assert(CanPrint::print("test"));
    assert(!CanPrint::print(a));

    return 0;
}
