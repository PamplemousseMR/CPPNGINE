#pragma once

#include <vector>
#include <initializer_list>
#include <stdint.h>

/*
	This class test std::initializer_list

	Constructor call with {} instead of ()
*/
class InitializationLists
{

public:

    InitializationLists(int);

    InitializationLists( std::initializer_list< int > );

	bool isList() const;

private:

	bool m_isList = false;

	std::vector<int> m_list{};

    size_t m_size = 0;

};
