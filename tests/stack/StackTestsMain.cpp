#include "StackTests.hpp"
#include <iostream>
#include <vector>

#include "PascalTest.hpp"

int main()
{
	int arr[] =
	{
		1, 2, 3, 4, 5
	};
	StackTest<int> test(arr, arr + 5);

	test.Push();
	test.Push();
	test.Push();
	test.Push();
	test.Push();
	test.Push();
	test.Empty();
	test.Push();
	test.Pop();
	test.ComparisonOverload();
}
