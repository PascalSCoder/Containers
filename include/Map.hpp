#pragma once

#include <functional>
#include <utility>
#include <map>
#include "../utils/bidirectional_iterator.hpp"
#include "../utils/binary_tree.hpp"

namespace ft
{

template <	class _Key,													// map::key_type
			class _T,													// map::mapped_type
			class Compare = std::less<_Key>,							// map::key_compare
			class Alloc = std::allocator<std::pair<const _Key, _T> >	// map::allocator_type
			>
class map
{
public:

	// template <class Key, class T, class Compare, class Alloc>
	// class map<Key,T,Compare,Alloc>::value_compare
	// {	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	// 	friend class map;
	// 	protected:
	// 	Compare comp;
	// 	value_compare (Compare c) : comp(c) {}	// constructed with map's comparison object
	// 	public:
	// 	typedef bool result_type;
	// 	typedef value_type first_argument_type;
	// 	typedef value_type second_argument_type;
	// 	bool operator() (const value_type& x, const value_type& y) const
	// 	{
	// 		return comp(x.first, y.first);
	// 	}
	// }

	typedef _Key									key_type;
	typedef _T										mapped_type;
	typedef std::pair<const key_type, mapped_type>	value_type;
	typedef Compare									key_compare;
	typedef Alloc									allocator_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer	const_pointer;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;

	typedef typename bidirectional_iterator<value_type>			iterator;
	typedef typename bidirectional_iterator<value_type const>	const_iterator;
	typedef typename reverse_iterator<iterator>			reverse_iterator;
	typedef typename reverse_iterator<const_iterator>	const_reverse_iterator;

#pragma region Constructors/Destructors

	// empty (1)
	explicit map (const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
	{
	}

	// range (2)
// template <class InputIterator>
// 	map (InputIterator first, InputIterator last,
// 		const key_compare& comp = key_compare(),
// 		const allocator_type& alloc = allocator_type());

	// copy (3)
	// map (const map& x)
	// {
	// }

	// map& operator= (const map& x)
	// {
	// }

#pragma endregion

	mapped_type& operator[] (const key_type& k)
	{
	}

#pragma region Iterators

	// iterator begin()
	// {
	// }

	// const_iterator begin() const
	// {
	// }

	// iterator end()
	// {
	// }

	// const_iterator end() const
	// {
	// }

	// reverse_iterator rbegin()
	// {
	// }

	// const_reverse_iterator rbegin() const
	// {
	// }

	// reverse_iterator rend()
	// {
	// }

	// const_reverse_iterator rend() const
	// {
	// }

#pragma endregion

#pragma region Capacity

	bool empty() const
	{
		return _size == 0;
	}

	size_type size() const
	{
		return _size;
	}

	size_type size() const
	{
		return _alloc.max_size();
	}

#pragma endregion

#pragma region Modifiers

	// single element (1)
	// pair<iterator,bool> insert (const value_type& val)
	// {
	// }

	// with hint (2)
	// iterator insert (iterator position, const value_type& val)
	// {
	// }

	// range (3)
	// template <class InputIterator>
	// void insert (InputIterator first, InputIterator last)
	// {
	// }

	// single element (1)
	// void erase (iterator position)
	// {
	// }

	// with key (2)
	// size_type erase (const key_type& k)
	// {
	// }

	// range (3)
	// void erase (iterator first, iterator last)
	// {
	// }

	// void swap (map& x)
	// {
	// }

	// void clear()
	// {
	// }

#pragma endregion

#pragma region Observers

	key_compare key_comp() const
	{
		return _comp;
	}

	// value_compare value_comp() const
	// {
	// 	return 
	// }

#pragma endregion

#pragma region Operations

	// iterator find (const key_type& k)
	// {
	// }

	// const_iterator find (const key_type& k) const
	// {
	// }

	// size_type count (const key_type& k) const
	// {
	// }

	// iterator lower_bound (const key_type& k)
	// {
	// }

	// const_iterator lower_bound (const key_type& k) const
	// {
	// }

	// iterator upper_bound (const key_type& k)
	// {
	// }

	// const_iterator upper_bound (const key_type& k) const
	// {
	// }

	// pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	// {
	// }

	// pair<iterator,iterator> equal_range (const key_type& k)
	// {
	// }

#pragma endregion

	allocator_type get_allocator() const
	{
		return _alloc;
	}

private:
	BST<value_type> _data;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;
	key_compare		_comp;
};

}
