#pragma once

#include "Commun.h"

#include <string>

/*
	this class test std::ref

	cast operator
*/
class CastOperator : Commun
{

public:

	static void launchTest();

public:

	explicit operator int() const;

private:

	CastOperator(const std::string&);

private:

	std::string m_str;

};