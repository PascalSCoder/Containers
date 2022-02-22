#pragma once

#include <string>

class PascalTest
{
public:
	void Run(bool (*test)(), std::string title);

private:
	void PrintCase(std::string str) const;
	void OK() const;
	void KO() const;

};
