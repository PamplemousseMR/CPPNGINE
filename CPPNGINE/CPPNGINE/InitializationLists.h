#pragma once

#include <vector>
#include <initializer_list>

class InitializationLists
{

public:

	InitializationLists(int);
	InitializationLists(std::initializer_list<int>);

	bool isList() const;

private:

	bool m_isList = false;
	std::vector<int> m_list{};
	int m_size = 0;

};

