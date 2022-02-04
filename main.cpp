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
void	Test(V& vec)
{
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	
	vec.push_back(42);
	
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << " " << vec[i];
	}
	std::cout << std::endl;

	std::cout << "Max size: " << vec.max_size() << std::endl;
}

int main()
{
	std::vector<int> stdVec(5);
	vector<int> ftVec(5);

	PrintTitle("STL Vector");
	Test(stdVec);
	PrintTitle("FT Vector");
	Test(ftVec);
}
