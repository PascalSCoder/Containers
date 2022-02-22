#include "../vector/Vector.hpp"
#include <vector>
#include <iostream>

#include "PascalTest.hpp"

bool TestPush()
{
	ft::vector<int> ftVec;
	std::vector<int> stdVec;

	ftVec.push_back(123);
	stdVec.push_back(123);
	if (ftVec.size() != stdVec.size())
		return false;
	if (ftVec[0] != stdVec[0])
		return false;
	return true;
}

int main()
{
	PascalTest test;
	test.Run(TestPush, "Push single number");
}
