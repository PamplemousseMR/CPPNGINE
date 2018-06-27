#include "Function.hpp"
#include "Function.hxx"

#include <assert.h>

/*
    this project test std::function implementation
*/
int main()
{
    Function<double(int, float)> t([](int _i, float _f) -> double {
        return _i + _f;
    });
    assert(t(1, 3.f) == 4.);

	return 0;
}
