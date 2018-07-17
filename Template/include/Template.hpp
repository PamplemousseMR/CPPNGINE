#pragma once

enum TEMPLATE
{
    STANDARD,
    SPECIALIZED,
    PARCIAL
};

class TemplateMethod
{

public:

    TemplateMethod() noexcept;

    template< typename T >
    TEMPLATE getTemplate() const noexcept;

};

class MultiTemplateMethod
{

public:

    MultiTemplateMethod() noexcept;

    template< typename T, typename U >
    TEMPLATE getTemplate() const noexcept;

};

template< typename T >
class TemplateClass
{

public:

    TemplateClass() noexcept;

    TEMPLATE getTemplate() const noexcept;

};

template<>
class TemplateClass< int >
{

public:

    TemplateClass() noexcept;

    TEMPLATE getTemplate() const noexcept;

};

template< typename T, typename U >
class MultiTemplateClass
{

public:

    MultiTemplateClass() noexcept;

    TEMPLATE getTemplate() const noexcept;

};

template<>
class MultiTemplateClass< int, int >
{

public:

    MultiTemplateClass() noexcept;

    TEMPLATE getTemplate() const noexcept;

};

template< typename T >
class MultiTemplateClass< T, int >
{

public:

    MultiTemplateClass() noexcept;

    TEMPLATE getTemplate() const noexcept;

};
