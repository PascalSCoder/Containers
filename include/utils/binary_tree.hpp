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
		struct BSTNode*	left;
		struct BSTNode*	right;
		struct BSTNode*	parent;
		pair_type		pair; // should this be replaced with pair_type const& throughout the whole code?

		BSTNode(pair_type& pair) : left(nullptr), right(nullptr), parent(nullptr), pair(pair) {}
	};

	BSTNode* _tree;

public:
	BST() : _tree(nullptr) {}

	pair_type Search(key_type const& key)
	{
		BSTNode* tree = _tree;
		while (tree != nullptr && tree->pair.first != key)
		{
			if (key < tree->pair.first)
				tree = tree->left;
			else
				tree = tree->right;
		}
		return tree->pair;
	}

	void Insert(pair_type pair)
	{
		BSTNode* node = new BSTNode(pair);
		BSTNode* branch = _tree;

		while (branch != nullptr)
		{
			if (pair.first < branch->pair.first)
			{
				if (branch->left != nullptr)
					branch = branch->left;
				else
					break;
			}
			else
			{
				if (branch->right != nullptr)
					branch = branch->right;
				else
					break;
			}
		}
		if (branch != nullptr)
		{
			node->parent = branch;

			if (pair.first < branch->pair.first)
				branch->left = node;
			else
				branch->right = node;
		}
		else
			_tree = node;
	}

	void PrintNodes(std::ostream& os, BSTNode* current, uint depth) const
	{
		if (_tree == nullptr)
			return;
		if (current == nullptr)
			current = _tree;

		if (current->right != nullptr)
		{
			PrintNodes(os, current->right, depth + 1);
		}

		std::string tabs;
		for (size_t i = 0; i < depth; i++)
		{
			tabs += "\t";
		}
		os << tabs << current->pair.first << std::endl;

		if (current->left != nullptr)
		{
			PrintNodes(os, current->left, depth + 1);
		}
	}
};

template<class T>
std::ostream& operator<<(std::ostream& os, BST<T> const& ref)
{
	ref.PrintNodes(os, nullptr, 0);
	return os;
}

}
