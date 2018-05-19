#include "Explicit.h"

#include <assert.h>

/*
    this project test explicit keyword
*/
int main()
{
    NotExplicit a1 = 1;      // OK: copy-initialization selects A::A(int)
    NotExplicit a2(2);       // OK: direct-initialization selects A::A(int)
    NotExplicit a3 {4, 5};   // OK: direct-list-initialization selects A::A(int, int)
    NotExplicit a4 = {4, 5}; // OK: copy-list-initialization selects A::A(int, int)
    NotExplicit a5 = (NotExplicit)1;   // OK: explicit cast performs static_cast
    if(a1)
    {
                             // OK: A::operator bool()
    }
    bool na1 = a1;           // OK: copy-initialization selects A::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization

//  Explicit b1 = 1;        // error: copy-initialization does not consider B::B(int)
    Explicit b2(2);         // OK: direct-initialization selects B::B(int)
    Explicit b3 {4, 5};     // OK: direct-list-initialization selects B::B(int, int)
//  Explicit b4 = {4, 5};   // error: copy-list-initialization does not consider B::B(int,int)
    Explicit b5 = (Explicit)1;     // OK: explicit cast performs static_cast
    if (b2)
    {
                            // OK: B::operator bool()
    }
//  bool nb1 = b2;          // error: copy-initialization does not consider B::operator bool()
    bool nb2 = static_cast<bool>(b2); // OK: static_cast performs direct-initialization

    return 0;
}
