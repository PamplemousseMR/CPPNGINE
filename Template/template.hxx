#include "template.hpp"

template< typename T >
TEMPLATE TemplateMethod::getTemplate() const noexcept
{
    return STANDARD;
}

template<>
TEMPLATE TemplateMethod::getTemplate< int >() const noexcept
{
    return SPECIALIZED;
}

template< typename T, typename U >
TEMPLATE MultiTemplateMethod::getTemplate() const noexcept
{
    return STANDARD;
}

template<>
TEMPLATE MultiTemplateMethod::getTemplate< int, int >() const noexcept
{
    return SPECIALIZED;
}

/*
 * Function templates cannot be partially specialised
 *
 * template< typename T >
 * TEMPLATE MultiTemplateMethod::getTemplate< T, int >() const noexcept
 * {
 *    return SPECIALIZED;
 * }
 */

template< typename T >
TemplateClass< T >::TemplateClass() noexcept
{
}

template< typename T >
TEMPLATE TemplateClass< T >::getTemplate() const noexcept
{
    return STANDARD;
}

TemplateClass< int >::TemplateClass() noexcept
{
}

TEMPLATE TemplateClass< int >::getTemplate() const noexcept
{
    return SPECIALIZED;
}

template< typename T >
TemplateClass< std::vector< T > >::TemplateClass() noexcept
{
}

template< typename T >
TEMPLATE TemplateClass< std::vector< T > >::getTemplate() const noexcept
{
    return CHANGE;
}

TemplateClass< std::vector< int > >::TemplateClass() noexcept
{
}

TEMPLATE TemplateClass< std::vector< int > >::getTemplate() const noexcept
{
    return CHANGESPE;
}

template< typename T, typename U >
MultiTemplateClass< T, U >::MultiTemplateClass() noexcept
{
}

template< typename T, typename U >
TEMPLATE MultiTemplateClass< T, U >::getTemplate() const noexcept
{
    return STANDARD;
}

MultiTemplateClass< int, int >::MultiTemplateClass() noexcept
{
}

TEMPLATE MultiTemplateClass< int, int >::getTemplate() const noexcept
{
    return SPECIALIZED;
}

template< typename T >
MultiTemplateClass< T, int >::MultiTemplateClass() noexcept
{
}

template< typename T >
TEMPLATE MultiTemplateClass< T, int >::getTemplate() const noexcept
{
    return PARCIAL;
}

template< typename T, typename U >
MultiTemplateClass< T, std::vector< U > >::MultiTemplateClass() noexcept
{
}

template< typename T, typename U >
TEMPLATE MultiTemplateClass< T, std::vector< U > >::getTemplate() const noexcept
{
    return CHANGE;
}
