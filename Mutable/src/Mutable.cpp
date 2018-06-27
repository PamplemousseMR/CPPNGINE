#include "Mutable.hpp"

int Mutable::addValue(int _a, int _b) const
{
	if(_a == m_firstCache && _b == m_secondCache)
	{
		return m_resCache;
	}
	m_resCache = _a + _b;	// big algorithm
	return m_resCache;
}
