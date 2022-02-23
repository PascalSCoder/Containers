#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

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

struct SubCheck
{
	const char	*title;
	bool		(*func)();
};

class PascalTest
{
public:
	void Run(void (*test)(), std::string title)
	{
		PrintCase(title);

		test();
		bool result = Checks();
		std::cout << "     Final: ";
		result ? OK() : KO();
		std::cout << std::endl;
	}

protected:
	virtual bool Checks() const = 0;

	void OK() const
	{
		std::cout << C_GREEN << "OK" << C_RESET;
	}

	void KO() const
	{
		std::cout << C_RED << "KO" << C_RESET;
	}

private:
	void PrintCase(std::string str) const
	{
		if (str.size() > 30)
			str.resize(30);
		std::cout << C_CYAN << std::setw(31) << std::setfill('.') << std::left << str << C_RESET;
	}

};

class TestFailedException : public std::exception
{
private:
	const char* _what;
public:
	TestFailedException(const char* msg) : _what(msg) {}
	const char* what() const throw()
	{
		return _what;
	}
};
