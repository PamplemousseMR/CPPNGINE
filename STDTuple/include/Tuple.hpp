#pragma once

#include <ostream>

template<typename... T>
class Tuple;

template<>
class Tuple<>
{

public:

    Tuple();

    std::ostream& operator <<(std::ostream&) const;

};

template<typename T, typename... R>
class Tuple<T, R...> : private Tuple<R...>
{

public:

    template<std::size_t S>
    struct Evaluator{};

    Tuple(T, R...);

    std::ostream& operator <<(std::ostream&) const;

    friend std::ostream& operator <<(std::ostream& _o, const Tuple<T, R...>& _t)
    {
        return _t.operator <<(_o);
    }

private:

    T m_this;

};

