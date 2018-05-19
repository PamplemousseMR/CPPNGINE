#include "Explicit.h"

NotExplicit::NotExplicit(int)
{

}

NotExplicit::NotExplicit(int, int)
{

}

NotExplicit::operator bool() const
{
    return true;
}

Explicit::Explicit(int)
{

}

Explicit::Explicit(int, int)
{

}

Explicit::operator bool() const
{
    return true;
}
