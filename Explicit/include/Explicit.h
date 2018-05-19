#pragma once

/*
    this class test explicit
*/
class NotExplicit
{

public:

    NotExplicit(int);

    NotExplicit(int, int);

    operator bool() const;

};

class Explicit
{

public:

    explicit Explicit(int);

    explicit Explicit(int, int);

    explicit operator bool() const;

};
