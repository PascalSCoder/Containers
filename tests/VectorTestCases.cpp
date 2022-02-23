#include "../vector/Vector.hpp"
#include <vector>
#include <iostream>

#include "PascalTest.hpp"
#include "VectorTest.hpp"

VectorTest<int> vectors;

void CasePushSingle()
{
	vectors.push_back(123);
}

void CaseMorePushes()
{
	for (size_t i = 1; i < 123123; i++)
	{
		vectors.push_back(i * i);
	}
}

void CasePopSingle()
{
	vectors.pop_back();
}

void CaseInsertSingles()
{
	for (size_t i = 0; i < 10; i++)
	{
		vectors.insert(i - (i / 2), i + 1000);
	}
}

void CaseInsertN()
{
	vectors.push_back(42);
	vectors.insert(1, 3333, 99);
}

int main()
{
	vectors.Run(CasePushSingle, "Push single number");
	vectors.Run(CaseMorePushes, "Push more numbers");
	vectors.Run(CasePopSingle, "Pop a single number");
	vectors.Run(CaseInsertSingles, "Inserting at different indexes");
	vectors.Run(CaseInsertN, "Insert N amount of value");
}
