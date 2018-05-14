#pragma once

#include "Commun.h"

#include <vector>
#include <initializer_list>

/*
	This class test std::initializer_list

	Constructor call with {} instead of ()
*/
class InitializationLists : public Commun
{

public:

	static void launchTest();

private:

	InitializationLists(int);

	InitializationLists(std::initializer_list<int>);

	bool isList() const;

private:

	bool m_isList = false;

	std::vector<int> m_list{};

	int m_size = 0;

};