#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec;
	int arr[9];
	vec.insert(vec.begin(), arr, arr + 9);
	std::cout << vec.capacity() << std::endl;
}