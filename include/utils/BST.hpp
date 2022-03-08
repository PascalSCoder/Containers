#pragma once

#include <iostream>
#include <utils/Pair.hpp>
#include <utils/BSTNode.hpp>

namespace ft
{

template<class _Alloc>
class BST
{
	typedef _Alloc								allocator_type;
	typedef typename allocator_type::value_type	pair_type;
	typedef BSTNode<pair_type>					node_type;
	typedef typename pair_type::first_type		key_type;
	typedef typename pair_type::second_type		value_type;
	typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;

private:

	node_type* _tree;
	node_allocator_type _alloc;

public:
	BST(const allocator_type& alloc = allocator_type()) : _tree(nullptr)
	{
		_alloc = alloc;
	}

	pair_type& Search(key_type const& key)
	{
		node_type* branch = _tree;
		while (branch != nullptr && branch->pair.first != key)
		{
			if (key < branch->pair.first)
				branch = branch->left;
			else
				branch = branch->right;
		}
		return branch->pair;
	}

	// Allocates a new node and inserts it on the right position according to key in tree.
	// Returns the new node 
	node_type* Insert(pair_type const& pair)
	{
		node_type* branch = _tree;

		while (branch != nullptr) // Traverse tree
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

		node_type* node = _alloc.allocate(1);
		if (branch != nullptr) // branch = parent, now insert left or right
		{
			node->parent = branch;
			if (pair.first < branch->pair.first)
				branch->left = node;
			else
				branch->right = node;
		}
		else // branch = root, set root to new node
			_tree = node;
		return node;
	}

	void PrintNodes(std::ostream& os, node_type* current, uint depth) const
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

template<class Alloc>
std::ostream& operator<<(std::ostream& os, BST<Alloc> const& ref)
{
	ref.PrintNodes(os, nullptr, 0);
	return os;
}

}
