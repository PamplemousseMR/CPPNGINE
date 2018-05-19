#pragma once

#include <ostream>

template<typename O, typename T>
class HasStreamOperator
{

private:

    typedef char yes[1];

    typedef char no[2];

private:

    template<std::size_t size>
    struct TemplateEvaluator
    {
    };

public:

    template<typename Out, typename Type>
    static yes& hasStreamOperator(TemplateEvaluator<sizeof(*(Out*)nullptr << *(Type*)nullptr)>* templateEvaluator = nullptr);

    template<typename Out, typename Type>
    static no& hasStreamOperator(...);

    static const bool value = sizeof(hasStreamOperator<O, T>(nullptr)) == sizeof(yes);

};

template<bool C>
struct enable_if
{
    typedef void* type;
};

template<>
struct enable_if<0>
{
};

class CanPrint
{

public:

    template<typename U>
    static bool print(const U& _obj, typename enable_if<HasStreamOperator<std::ostream, U>::value>::type* = nullptr)
    {
        return true;
    }

    template<typename U>
    static bool print(const U&, typename enable_if<!HasStreamOperator<std::ostream, U>::value>::type* = nullptr)
    {
        return false;
    }

};
