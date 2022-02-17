#include "Vector.hpp"
#include <vector>

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
	std::cout << std::endl << C_CYAN << str << C_RESET << std::endl;
}

#pragma endregion

class Data
{
	public:
	Data() {}
	Data(int n) : num(n) {}
	~Data()
	{
		std::cout << "Data destroyed" << std::endl;
	}
	int	num;
};

template<class V>
void	PrintSizes(V const& vec)
{
	std::cout << "Size: " << vec.size() << "/" << vec.capacity() << std::endl;
}

template<class V>
void	PrintValues(V const& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}

template<class V>
void	Test(V& vec)
{
	PrintSizes(vec);
	vec.push_back(42);

	PrintSizes(vec);

	vec.resize(3);
	PrintSizes(vec);
	vec.resize(9);
	PrintSizes(vec);
	vec.resize(61);
	PrintSizes(vec);
	
	while (vec.size() > 3)
	{
		vec.pop_back();
	}
	vec[0] = 42;
	vec[1] = 21;
	vec[2] = 10;
	PrintSizes(vec);
	PrintValues(vec);

	// vec.resize(42);
	// PrintSizes(vec);

	std::cout << "front: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;

	vec.reserve(124);
	PrintSizes(vec);
	vec.reserve(111);
	PrintSizes(vec);
	vec.reserve(125);
	PrintSizes(vec);

	typename V::iterator begin = vec.begin();
	std::cout << "begin: " << *begin << std::endl;
	typename V::iterator end = vec.end();
	while (begin != end)
	{
		std::cout << " " << *begin;
		begin++;
	}
	std::cout << std::endl;
	vec.erase(begin - 2);
	begin = vec.begin();
	std::cout << "begin: " << *begin << std::endl;
	end = vec.end();
	while (begin != end)
	{
		std::cout << " " << *begin;
		begin++;
	}
	std::cout << std::endl;
	// std::cout << "Max size: " << vec.max_size() << std::endl;
}

template<class V, class T>
void	PushBackRange(V& vec, T begin, T end)
{
	while (begin != end)
	{
		vec.push_back(*begin);
		begin++;
	}
}

template<class V>
void	Test2(V& vec)
{
	typename V::reverse_iterator begin = vec.rbegin();
	typename V::reverse_iterator end = vec.rend();
	int arr[] = { 12, 24, 36, 48, 60};
	PushBackRange(vec, arr, arr + 5);
	while (begin != end)
	{
		std::cout << " " << *begin;
		begin++;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> stdVec(5);
	ft::vector<int> ftVec(5);

	// std::vector<int>::reverse_iterator

	PrintTitle("STL Vector");
	Test2(stdVec);
	PrintTitle("FT Vector");
	Test2(ftVec);
}
