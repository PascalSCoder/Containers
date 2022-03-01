#include <Vector.hpp>
#include <vector>
#include <iostream>

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

void CaseInsertRange()
{
	int* ints = new int[12312];
	vectors.insert(1, ints, ints + 12312);
	delete[] ints;
}

void CaseInsertFill()
{
	vectors.push_back(42);
	vectors.insert(1, 3333, 99);
}

void CaseConstructIter()
{
	int* ints = new int[33];
	for (size_t i = 0; i < 33; i++)
	{
		ints[i] = i * i;
	}
	vectors.ConstructIter(ints, ints + 33);
	delete[] ints;
}

void CaseConstructBadIter()
{
	vectors.ConstructIter(nullptr, nullptr);
}

void CaseAssignRange()
{
	int* ints = new int[123];
	vectors.assign(ints, ints + 123);
	delete[] ints;
}

void CaseAssignFill()
{
	vectors.assign(10, 42);
}

// void CaseErase()
// {

// }

// void CaseEraseIter()
// {
// }
