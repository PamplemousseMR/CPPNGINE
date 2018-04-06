#pragma once

template< class F >
class Slot;

template< class F, class... A >
class Slot< F(A...) > 
{

public:

	Slot(F(*_fun)(A...));

	F call(A...);

private:

	F(*m_function)(A...) = nullptr;

};
