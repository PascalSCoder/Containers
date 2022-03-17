#pragma once

#include <iostream>
#include <utils/pair.hpp>
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

	value_type& Search(key_type const& key)
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

// make private?
	node_type* SearchNode(key_type const& key)
	{
		node_type* branch = _tree;
		while (branch != nullptr && branch->pair.first != key)
		{
			if (key < branch->pair.first)
				branch = branch->left;
			else
				branch = branch->right;
		}
		return branch;
	}

	node_type* TraverseRight(node_type* branch, int* depth)
	{
		if (branch == nullptr)
			return nullptr;
		while (1)
		{
			(*depth)++;
			if (branch->right != nullptr)
				branch = branch->right;
			else
				break;
		}
		return branch;
	}

	node_type* TraverseLeft(node_type* branch, int* depth)
	{
		if (branch == nullptr)
			return nullptr;
		while (1)
		{
			(*depth)++;
			if (branch->left != nullptr)
				branch = branch->left;
			else
				break;
		}
		return branch;
	}

	bool Remove(key_type const& key)
	{
		node_type* node = SearchNode(key);

		int left = 0, right = 0;
		node_type* deepestLeft = TraverseRight(node->left, &left);
		node_type* deepestRight = TraverseLeft(node->right, &right);
		std::cout << "left: " << left << " | right: " << right << std::endl;
		if (left >= right)
		{
			std::cout << "Should move " << deepestLeft->pair.first << " to the place of " << key << std::endl;
		}
		else
		{
			std::cout << "Should move " << deepestRight->pair.first << " to the place of " << key << std::endl;
		}
		return true;
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
		_alloc.construct(node, node_type(pair));
		if (branch != nullptr) // branch = parent, now insert left or right
		{
			node->parent = branch;
			if (pair.first < branch->pair.first)
				branch->left = node;
			else
				branch->right = node;
		}
		else // branch = root, set root to new node
		{
			std::cout << "Root set" << std::endl;
			_tree = node;
		}
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
