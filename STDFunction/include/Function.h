#pragma once

/*
    this class test std::function
*/
template<typename T>
class Function;

template<typename R, typename... A >
class Function< R(A...) >
{

public:

    Function(R(A...));

    R operator() (A... _args);

private:

    R(*m_fun)(A...);

};
