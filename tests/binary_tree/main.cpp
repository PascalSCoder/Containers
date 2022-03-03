#include <utils/binary_tree.hpp>
#include <utils/pair.hpp>
#include <iostream>

int main()
{
	ft::BST<ft::pair<int, int> > bst;

	bst.Insert(ft::pair<int, int>(10, 5));
	bst.Insert(ft::pair<int, int>(11, 5));
	bst.Insert(ft::pair<int, int>(12, 5));
}
