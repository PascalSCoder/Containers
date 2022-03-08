#pragma once

template<class _Pair>
struct BSTNode
{
	BSTNode*	left;
	BSTNode*	right;
	BSTNode*	parent;
	_Pair		pair;

	BSTNode(_Pair& ref) : left(nullptr), right(nullptr), parent(nullptr), pair(ref) {}
};
