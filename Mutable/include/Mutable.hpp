#pragma once

class Mutable
{

public:

	int addValue(int, int) const;

private:

	mutable int m_firstCache;

	mutable int m_secondCache;

	mutable int m_resCache;

};
