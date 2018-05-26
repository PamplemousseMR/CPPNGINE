#pragma once

class MoveSemantics
{

public:

    enum CONSTRUCT_TYPE
    {
        STANDAR,
        COPY_CONSTRUCT,
        MOVE_CONSTRUCT,
        COPY_AFFECTATION,
        MOVE_AFFECTATION,
    };

public:

    static MoveSemantics make(int);

public:

    MoveSemantics(int);

    MoveSemantics(const MoveSemantics&);

    MoveSemantics(MoveSemantics&&);

    MoveSemantics& operator =(const MoveSemantics&);

    MoveSemantics& operator =(MoveSemantics&&);

public:

    CONSTRUCT_TYPE m_constructType;

};
