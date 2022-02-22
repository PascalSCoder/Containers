#include <iostream>
#include <stack>

#include "Stack.hpp"

#pragma region Debug

#define C_RESET  "\x1B[0m"
#define C_RED  "\x1B[31m"
#define C_GREEN  "\x1B[32m"
#define C_YELLOW  "\x1B[33m"
#define C_BLUE  "\x1B[34m"
#define C_MAGENTA  "\x1B[35m"
#define C_CYAN  "\x1B[36m"
#define C_WHITE  "\x1B[37m"

void PrintTitle(std::string str)
{
	std::cerr << std::endl << C_CYAN << str << C_RESET << std::endl;
}

#pragma endregion

template<class st>
void EqualTest(st lhs)
{
	PrintTitle("EqualTest");

	st rhs = lhs;
	std::cout << (lhs == rhs) << std::endl;
	rhs.push(42);
	std::cout << (lhs == rhs) << std::endl;
	lhs.push(42);
	std::cout << (lhs == rhs) << std::endl;
}

template<class st>
void NotEqualTest(st lhs)
{
	PrintTitle("NotEqualTest");

	st rhs = lhs;
	std::cout << (lhs != rhs) << std::endl;
	rhs.push(42);
	std::cout << (lhs != rhs) << std::endl;
	lhs.push(42);
	std::cout << (lhs != rhs) << std::endl;
}

template<class st>
void GreaterTest(st lhs)
{
	PrintTitle("GreaterTest");

	st rhs = lhs;
	std::cout << (lhs > rhs) << std::endl;
	lhs.push(42);
	std::cout << (lhs > rhs) << std::endl;
	rhs.push(41);
	std::cout << (lhs > rhs) << std::endl;
	rhs.push(0);
	std::cout << (lhs > rhs) << std::endl;
}

template<class st>
void SmallerTest(st lhs)
{
	PrintTitle("SmallerTest");

	st rhs = lhs;
	std::cout << (lhs < rhs) << std::endl;
	rhs.push(42);
	std::cout << (lhs < rhs) << std::endl;
	lhs.push(41);
	std::cout << (lhs < rhs) << std::endl;
	rhs.push(0);
	std::cout << (lhs < rhs) << std::endl;
}

template<class st>
void SmallerEqualTest(st lhs)
{
	PrintTitle("SmallerEqualTest");

	st rhs = lhs;
	std::cout << (lhs <= rhs) << std::endl;
	rhs.push(42);
	std::cout << (lhs <= rhs) << std::endl;
	lhs.push(42);
	std::cout << (lhs <= rhs) << std::endl;
	lhs.push(0);
	std::cout << (lhs <= rhs) << std::endl;
}

template<class st>
void GreaterEqualTest(st lhs)
{
	PrintTitle("GreaterEqualTest");

	st rhs = lhs;
	std::cout << (lhs >= rhs) << std::endl;
	lhs.push(42);
	std::cout << (lhs >= rhs) << std::endl;
	rhs.push(41);
	std::cout << (lhs >= rhs) << std::endl;
	rhs.push(0);
	std::cout << (lhs >= rhs) << std::endl;
}

template<class st>
void InitiateTests(st& stck)
{
	EqualTest(stck);
	NotEqualTest(stck);
	GreaterTest(stck);
	SmallerTest(stck);
	GreaterEqualTest(stck);
	SmallerEqualTest(stck);
}



int main(int argc, char **argv)
{
	std::stack<int> stl_stack;
	ft::stack<int> ft_stack;

	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]) == std::string("ft"))
			InitiateTests(ft_stack);
		else if (std::string(argv[i]) == std::string("stl"))
			InitiateTests(stl_stack);
	}
}
