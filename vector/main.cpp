#include <vector>
#include "Vector.hpp"
#include <iostream>

// template<class Container>
// void EqualTests(Container& vec)
// {
// 	Container copy(vec);
// 	std::cout << "Equal? " << (vec == copy) << std::endl;
// 	std::cout << "Greater? " << (vec > copy) << std::endl;
// }

int main()
{
	std::vector<int> stdVec;

	std::cout << "capacity: " << stdVec.capacity() << std::endl;
	for (size_t i = 0; i < 1; i++)
	{
		stdVec.push_back(i);
	}
	std::vector<int>::iterator pos = stdVec.begin();
	stdVec.insert(pos, 8, 99);
	for (size_t i = 0; i < stdVec.size(); i++)
	{
		std::cout << stdVec[i] << std::endl;
	}
	std::cout << "capacity: " << stdVec.capacity() << std::endl;
	stdVec.insert(stdVec.begin(), 1);
	std::cout << "capacity: " << stdVec.capacity() << std::endl;
	
}
/*
	ft::vector<int> ftVec;
	std::vector<int> stdVec;
	stdVec.push_back(123);
	ftVec.push_back(123);

	std::cout << "STD" << std::endl;
	EqualTests(stdVec);

	std::cout << "FT" << std::endl;
	EqualTests(ftVec);
*/