#pragma once

template<class T>
class CastOperator
{

public:

	CastOperator(T&);

	operator T&() const;
	operator const T&() const;

private:

	T* m_ref;

};