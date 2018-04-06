#pragma once

template< typename T >
class Ref
{

public:

	Ref(T& _ref);

	operator T&() const;
	operator const T&() const;

private:

	T* m_ref;

};

