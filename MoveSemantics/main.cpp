#include "moveSemantics.hpp"

#include <assert.h>

/*
    this project test movement semantics
*/
int main()
{
    assert(MoveSemantics::CONSTRUCT_TYPE::STANDAR == MoveSemantics(0).m_constructType);
    MoveSemantics toCopy(1);
    assert(MoveSemantics::CONSTRUCT_TYPE::COPY_CONSTRUCT == MoveSemantics(toCopy).m_constructType);
    assert(MoveSemantics::CONSTRUCT_TYPE::MOVE_CONSTRUCT == MoveSemantics(MoveSemantics::make(2)).m_constructType);
    MoveSemantics toAffect(3);
    MoveSemantics toBeAffected(3);
    assert(MoveSemantics::CONSTRUCT_TYPE::COPY_AFFECTATION == (toAffect = toBeAffected).m_constructType);
    MoveSemantics toBeMoveAffect(4);
    assert(MoveSemantics::CONSTRUCT_TYPE::MOVE_AFFECTATION == (toBeMoveAffect = MoveSemantics::make(4)).m_constructType);

    return 0;
}
