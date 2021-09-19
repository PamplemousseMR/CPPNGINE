#pragma once

template<typename T>
class Function;

template<typename R, typename... A >
class Function< R(A...) >
{

public:

    Function(R(A...));

    R operator() (A... _args);

    int m_arity;

private:

    R(*m_fun)(A...);

};

#include "function.hxx"
