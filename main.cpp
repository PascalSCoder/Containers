#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec;
	int arr[1024];
	vec = std::vector<int>(arr, arr + 123);
	std::cout << vec.capacity() << std::endl;
	vec.assign(124, 0);
	std::cout << vec.capacity() << std::endl;
	vec.assign(125, 0);
	std::cout << vec.capacity() << std::endl;
}
