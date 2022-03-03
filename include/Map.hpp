#pragma once

#include <functional>
#include <utility>
#include <map>
#include "../utils/bidirectional_iterator.hpp"

template <	class _Key,													// map::key_type
			class _T,													// map::mapped_type
			class Compare = std::less<_Key>,							// map::key_compare
			class Alloc = std::allocator<std::pair<const _Key, _T> >	// map::allocator_type
			>
class map
{
public:

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

	// empty (1)
	explicit map (const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
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
};
