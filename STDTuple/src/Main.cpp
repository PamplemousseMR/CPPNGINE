#include "Tuple.h"
#include "Tuple.hxx"

/*
    this project test std::tuple<> implementation
*/
int main()
{
    Tuple<int, float, int, bool> t(1, 1.2f, 1, true);

	return 0;
}
