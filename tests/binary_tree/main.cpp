#include <utils/binary_tree.hpp>
#include <utils/pair.hpp>
#include <iostream>

#include <map>


int main()
{
	std::map<int, int> map;

	map.insert(std::pair<int, int>(10, 5));
	map.insert(std::pair<int, int>(13, 5));
	map.insert(std::pair<int, int>(7, 5));
	map.insert(std::pair<int, int>(15, 5));
	map.insert(std::pair<int, int>(12, 5));
	map.insert(std::pair<int, int>(1, 5));
	map.insert(std::pair<int, int>(6, 5));

	typename std::map<int, int>::iterator first = map.begin();
	typename std::map<int, int>::iterator last = map.end();
}

// int main()
// {
// 	ft::BST<ft::pair<int, int> > bst;

// 	bst.Insert(ft::pair<int, int>(10, 5));
// 	bst.Insert(ft::pair<int, int>(13, 5));
// 	bst.Insert(ft::pair<int, int>(7, 5));
// 	bst.Insert(ft::pair<int, int>(15, 5));
// 	bst.Insert(ft::pair<int, int>(12, 5));
// 	bst.Insert(ft::pair<int, int>(1, 5));
// 	bst.Insert(ft::pair<int, int>(6, 5));
// 	bst.Insert(ft::pair<int, int>(18, 5));
// 	bst.Insert(ft::pair<int, int>(11, 5));
// 	bst.Insert(ft::pair<int, int>(3, 42));
// 	bst.Insert(ft::pair<int, int>(20, 5));

// 	ft::pair<int, int> result = bst.Search(3);
// 	std::cout << "result: " << result.second << std::endl;

// 	std::cout << bst << std::endl;
// }
