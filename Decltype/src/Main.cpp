#include <assert.h>
#include <type_traits>

/*
    this project test decltype and auto keyword
*/
int foo()
{
    int i = 1;
    return i;
}

int main()
{
    int n = 10;

    decltype(n) a = 20;             // a is an "int" [id-expression]
    assert(std::is_integral<decltype(n)>::value);

    decltype((n)) b = a;            // b is an "int &" [(n) is an lvalue]
    assert( (std::is_same<decltype((n)), int&>::value) );

    decltype(foo()) c = foo();      // c is an "int" [rvalue]
    assert( (std::is_same<decltype(foo()), int>::value) );

    decltype(foo())&& d = foo();  // int &&
    assert( (std::is_same<decltype(foo())&&, int&&>::value) );

    auto e = n;
    assert( (std::is_same<decltype(e), decltype(n)>::value) );

    return 0;
}
