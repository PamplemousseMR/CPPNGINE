#pragma once

#include "Slot.h"

#include <vector>

template<class F>
class Signal;

template< class F, class... A >
class Signal< F(A...) >
{

public:

	Signal();

	void connect(Slot< F(A...) >);
	void emit(A...);

private:

	std::vector< Slot< F(A...) > > m_slots;

};
