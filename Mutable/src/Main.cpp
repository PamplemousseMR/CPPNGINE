#include "Mutable.h"

#include <assert.h>

/*
	this project test mutable keyword
*/
int main()
{
	Mutable m;
	assert(m.addValue(1, 3) == 4);
	assert(m.addValue(1, 3) == 4);

    return 0;
}
