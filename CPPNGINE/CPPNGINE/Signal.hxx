#include "Signal.h"

template<class F, class... A>
Signal< F(A...) >::Signal()
{
}

template<class F, class... A>
void Signal< F(A...) >::connect(Slot< F(A...) > _slot)
{
	m_slots.push_back(_slot);
}

template<class F, class... A>
void Signal< F(A...) >::emit(A... _args)
{
	for (Slot< F(A...) > slot : m_slots)
	{
		slot.call(_args...);
	}
}