#pragma once

#include <iostream>
#include "pair.hpp"

namespace ft
{

template<class _Pair>
class BST
{

typedef _Pair						pair_type;
typedef typename _Pair::first_type	key_type;
typedef typename _Pair::second_type	value_type;

private:

	struct BSTNode
	{
		struct BSTNode*	_left;
		struct BSTNode*	_right;
		struct BSTNode* _parent;
		pair_type&		_pair;

	public:
		BSTNode(pair_type& pair) : _left(nullptr), _right(nullptr), _parent(nullptr), _pair(pair) {}
	};

	BSTNode* _tree;

public:
	BST() : _tree(nullptr) {}

	BSTNode* Search(key_type const& key)
	{
		BSTNode* tree = _tree;
		while (tree != nullptr && tree->pair.first != key)
		{
			if (key < tree->pair.first)
				tree = tree->left;
			else
				tree = tree->right;
		}
		return tree;
	}

	void Insert(pair_type pair)
	{
		BSTNode* node = new BSTNode(pair);
		BSTNode* branch = _tree;
		while (branch != nullptr)
		{
			if (pair.first < branch->_pair.first)
				branch = branch->_left;
			else
				branch = branch->_right;
		}
		if (branch != nullptr)
		{
			node->_parent = branch;
			if (pair.first < branch->_pair.first)
				branch->_left = node;
			else
				branch->_right = node;
		}
	}
};

}
