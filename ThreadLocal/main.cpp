#include <assert.h>
#include <string>
#include <thread>

/*
	this project test thread_local keyword
*/
thread_local unsigned int val = 1;

void increase()
{
	assert(val == 1);
	++val; // modifying outside a lock is okay; this is a thread-local variable
	assert(val == 2);
}

int main()
{
	std::thread a(increase);
	std::thread b(increase);
	a.join();
	b.join();

	assert(val == 1);

	return 0;
}
