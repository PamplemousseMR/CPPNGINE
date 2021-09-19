#include "moveSemantics.hpp"

MoveSemantics MoveSemantics::make(int _i)
{
    MoveSemantics res(_i);
    return res;
}

MoveSemantics::MoveSemantics(int)
    :   m_constructType(STANDAR)
{

}

MoveSemantics::MoveSemantics(const MoveSemantics&)
    :   m_constructType(COPY_CONSTRUCT)
{

}

MoveSemantics::MoveSemantics(MoveSemantics&&)
    :   m_constructType(MOVE_CONSTRUCT)
{

}

MoveSemantics& MoveSemantics::operator =(const MoveSemantics&)
{
    m_constructType = COPY_AFFECTATION;
    return *this;
}

MoveSemantics& MoveSemantics::operator =(MoveSemantics&&)
{
    m_constructType = MOVE_AFFECTATION;
    return *this;
}
