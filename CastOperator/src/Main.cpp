#include "CastOperator.h"
#include "CastOperator.hxx"

#include <assert.h>

/*
    this project test cast operator
*/
int main()
{
    CastOperator<float> co(1.2f);
    assert(co == 4);
    const float (*pa)[3] = co;
    assert(*pa[0] == 1.2f);

    return 0;
}
