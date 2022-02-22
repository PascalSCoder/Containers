#include <iostream>
#include <string>
#include <iomanip>

#include "PascalTest.hpp"

#pragma region Colors

#define C_RESET  "\x1B[0m"
#define C_RED  "\x1B[31m"
#define C_GREEN  "\x1B[32m"
#define C_YELLOW  "\x1B[33m"
#define C_BLUE  "\x1B[34m"
#define C_MAGENTA  "\x1B[35m"
#define C_CYAN  "\x1B[36m"
#define C_WHITE  "\x1B[37m"

#pragma endregion

void PascalTest::PrintCase(std::string str) const
{
	if (str.size() > 25)
		str.resize(25);
	std::cout << C_CYAN << std::setw(26) << std::setfill('.') << std::left << str << C_RESET;
}

void PascalTest::OK() const
{
	std::cout << C_GREEN << "OK" << C_RESET << std::endl;
}

void PascalTest::KO() const
{
	std::cout << C_RED << "KO" << C_RESET << std::endl;
}

void PascalTest::Run(bool (*test)(), std::string title)
{
	PrintCase(title);
	test() ? OK() : KO();
}
