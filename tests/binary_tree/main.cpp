#include <utils/BST.hpp>
#include <utils/pair.hpp>
#include <iostream>

#include <map>
#include <Map.hpp>


// int main()
// {
// 	std::map<int, int> map;

// 	map.insert(std::pair<int, int>(10, 5));
// 	map.insert(std::pair<int, int>(13, 5));
// 	map.insert(std::pair<int, int>(7, 5));
// 	map.insert(std::pair<int, int>(15, 5));
// 	map.insert(std::pair<int, int>(12, 5));
// 	map.insert(std::pair<int, int>(1, 5));
// 	map.insert(std::pair<int, int>(6, 5));

// 	typename std::map<int, int>::iterator first = map.begin();
// 	typename std::map<int, int>::iterator last = map.end();
// }



int main()
{
	ft::map<int, int> map;
	map.insert(std::pair<int, int>(1, 42));
	map.insert(std::pair<int, int>(-12, 42));
	map.insert(std::pair<int, int>(5, 42));
	map.insert(std::pair<int, int>(8, 42));
	map.insert(std::pair<int, int>(7, 42));
	map.insert(std::pair<int, int>(4, 42));
	map.insert(std::pair<int, int>(-9, 42));
	map.insert(std::pair<int, int>(0, 42));
	map.RemoveKey(5);

	// ft::BST<ft::pair<int, int> > bst;

	// ft::pair<int, int> result = bst.Search(3);
	// std::cout << "result: " << result->second << std::endl;

	// std::cout << bst << std::endl;
}
