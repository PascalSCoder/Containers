#pragma once

#include <cstddef>

// difference_type		Type to express the result of subtracting one iterator from another.
// value_type			The type of the element the iterator can point to.
// pointer				The type of a pointer to an element the iterator can point to.
// reference			The type of a reference to an element the iterator can point to.
// iterator_category	The iterator category. It can be one of these:
						// input_iterator_tag
						// output_iterator_tag
						// forward_iterator_tag
						// bidirectional_iterator_tag
						// random_access_iterator_tag

/*
	Note that any custom class will have a valid instantiation of iterator_traits if it publicly inherits the base class std::iterator.
*/

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag {};
struct bidirectional_iterator_tag {};
struct random_access_iterator_tag {};

// template <class Iterator> class iterator_traits;
// template <class T> class iterator_traits<T*>
// template <class T> class iterator_traits<const T*>
template <class T>
class iterator_traits
{
	typedef ptrdiff_t	difference_type;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			reference;
	typedef iterator_category;
};
