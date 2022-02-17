#pragma once

#include <vector>
#include <iostream>

#include "Stack.hpp"
#include <stack>
#include <iomanip>

#pragma region Debug

#define C_RESET  "\x1B[0m"
#define C_RED  "\x1B[31m"
#define C_GREEN  "\x1B[32m"
#define C_YELLOW  "\x1B[33m"
#define C_BLUE  "\x1B[34m"
#define C_MAGENTA  "\x1B[35m"
#define C_CYAN  "\x1B[36m"
#define C_WHITE  "\x1B[37m"

void Debug(std::string str)
{
	std::cout << C_CYAN << std::setw(10) << std::setfill('.') << std::left << str << C_RESET;
}

void OK()
{
	std::cout << C_GREEN << "OK" << C_RESET << std::endl;
}

void KO()
{
	std::cout << C_RED << "KO" << C_RESET << std::endl;
}

#pragma endregion

template<class T>
class StackTest
{
private:

	std::vector<T> _seed;
	typename std::vector<T>::iterator _it;

	ft::stack<T> _ftStack;
	std::stack<T> _stdStack;

	void Check()
	{
		if (_stdStack.size() == _ftStack.size() && (_stdStack.size() == 0 || _stdStack.top() == _ftStack.top()))
			OK();
		else
			KO();
	}

	T& GetFromSeed()
	{
		if (_it == _seed.end())
			_it = _seed.begin();
		return *(_it++);
	}

	bool EqualTest()
	{
		Debug("Case ==");

		ft::stack<T> copy(_ftStack);
		if (!(_ftStack == copy))
			return false;
		copy.push(0);
		if (_ftStack == copy)
			return false;
		return true;
	}

	bool NotEqualTest()
	{
		Debug("Case !=");

		ft::stack<T> copy(_ftStack);
		if (_ftStack != copy)
			return false;
		copy.push(0);
		if (!(_ftStack != copy))
			return false;
		return true;
	}

	bool GreaterTest()
	{
		Debug("Case >");

		ft::stack<T> copy(_ftStack);
		if (_ftStack > copy)
			return false;
		copy.push(0);
		if (!(copy > _ftStack))
			return false;
		return true;
	}

	bool SmallerTest()
	{
		Debug("Case <");

		ft::stack<T> copy(_ftStack);
		if (_ftStack < copy)
			return false;
		copy.push(0);
		if (copy < _ftStack)
			return false;
		return true;
	}

	bool SmallerEqualTest()
	{
		Debug("Case <=");

		ft::stack<T> copy(_ftStack);
		if (!(_ftStack <= copy))
			return false;
		copy.push(0);
		if (copy <= _ftStack)
			return false;
		return true;
	}

	bool GreaterEqualTest()
	{
		Debug("Case >=");

		ft::stack<T> copy(_ftStack);
		if (!(_ftStack >= copy))
			return false;
		copy.push(0);
		if (_ftStack >= copy)
			return false;
		return true;
	}

public:

	template<class Iterator>
	StackTest(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			_seed.push_back(*begin);
			begin++;
		}
		_it = _seed.begin();
	}

	void PushValue(T& val)
	{
		Debug("Push");
		_ftStack.push(val);
		_stdStack.push(val);
		Check();
	}

	void Push()
	{
		T& val = GetFromSeed();
		Debug("Push");
		_ftStack.push(val);
		_stdStack.push(val);
		Check();
	}

	void Pop()
	{
		Debug("Pop");
		_ftStack.pop();
		_stdStack.pop();
		Check();
	}

	void Empty()
	{
		Debug("Empty");
		_ftStack.empty();
		_stdStack.empty();
		Check();
	}

	void Reset()
	{
		_ftStack = ft::stack<T>();
		_stdStack = std::stack<T>();
	}

	void ComparisonOverload()
	{
		EqualTest() ? OK() : KO();
		NotEqualTest() ? OK() : KO();
		GreaterTest() ? OK() : KO();
		GreaterEqualTest() ? OK() : KO();
		SmallerTest() ? OK() : KO();
		SmallerEqualTest() ? OK() : KO();
	}
};
