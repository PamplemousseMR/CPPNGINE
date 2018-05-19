#include "InitializationLists.h"

#include <assert.h>

/*
    this project test std::initializer_list<> implementation
*/
int main()
{
	{
		InitializationLists in(1);
		assert(!in.isList());
	}
	{
		InitializationLists in{ 1, 2, 3 };
		assert(	in.isList());
	}

	return 0;
}
