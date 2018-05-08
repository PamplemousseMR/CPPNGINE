#include "InitializationLists.h"

#include <iostream>

InitializationLists::InitializationLists(int _i)
	:	m_size(1),
		m_list(_i)
{
}

InitializationLists::InitializationLists(std::initializer_list<int> _list)
	:	m_isList(true),
		m_size(_list.size()),
		m_list(_list.begin(), _list.end())
{
}

bool InitializationLists::isList() const
{
	return m_isList;
}

void InitializationListsTest()
{
	std::cout << "--- InitializationListsTest ---" << std::endl;
	{
		InitializationLists in(1);
		std::cout << "InitializationLists : () => " << std::boolalpha << in.isList() << std::endl;
	}
	{
		InitializationLists in{ 1, 2, 3 };
		std::cout << "InitializationLists : {} => " << std::boolalpha << in.isList() << std::endl;
	}
}