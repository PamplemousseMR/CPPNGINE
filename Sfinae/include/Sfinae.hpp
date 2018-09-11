#pragma once

#include <ostream>

template<typename O, typename T>
class HasStreamOperatorPtr
{

private:

    typedef char yes[1];

    typedef char no[2];

private:

    template<std::size_t size>
    struct TemplateEvaluator
    {
    };

private:

    template<typename Out, typename Type>
    static yes& hasStreamOperatorPtr(TemplateEvaluator<sizeof(*static_cast<Out*>(nullptr) << *static_cast<Type*>(nullptr))>* templateEvaluator = nullptr);

    template<typename Out, typename Type>
    static no& hasStreamOperatorPtr(...);

public:

    static const bool value = sizeof(hasStreamOperatorPtr<O, T>(nullptr)) == sizeof(yes);

};

template<typename O, typename T>
class HasStreamOperatorDecltypePtr
{

private:

    template<typename Out, typename Type>
    static constexpr auto hasStreamOperatorDecltypePtr(void*) -> decltype(*static_cast<Out*>(nullptr) << *static_cast<Type*>(nullptr), bool())
    {
        return true;
    }

    template<typename Out, typename Type>
    static constexpr bool hasStreamOperatorDecltypePtr(...)
    {
        return false;
    }

public:

	static const bool value = hasStreamOperatorDecltypePtr<O, T>(nullptr);

};

template<typename O, typename T>
class HasStreamOperatorDecltypeDeclvalPtr
{

private:

    template<typename Out, typename Type>
    static constexpr auto hasStreamOperatorDecltypeDeclvalPtr(void*) -> decltype(std::declval<Out>() << std::declval<Type>(), bool())
    {
        return true;
    }

    template<typename Out, typename Type>
    static constexpr bool hasStreamOperatorDecltypeDeclvalPtr(...)
    {
        return false;
    }

public:

	static const bool value = hasStreamOperatorDecltypeDeclvalPtr<O, T>(nullptr);

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
    static bool print(const U&, typename enable_if<HasStreamOperatorPtr<std::ostream, U>::value>::type* = nullptr)
    {
        return true;
    }

    template<typename U>
    static bool print(const U&, typename enable_if<!HasStreamOperatorPtr<std::ostream, U>::value>::type* = nullptr)
    {
        return false;
    }

};
