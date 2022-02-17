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



// Iterator tags as defined in the documentation
// We only use random_access_iterator_tag(vector) and bidirectional_iterator_tag(map),
// but it seems useful for possible future implementations to have the whole structure ready.
struct output_iterator_tag {};
struct input_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


// Base iterator traits struct:
// template <class Iterator> class iterator_traits;
template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};



// SPECIALIZATIONS NOT COMPLETE / NOT TESTED!
// do we need to dereference T for specializations?

// Specialization for <T *>:
template <class Iterator>
struct iterator_traits<Iterator*>
{
	typedef ptrdiff_t					difference_type;
	typedef Iterator					value_type;
	typedef Iterator*					pointer;
	typedef Iterator&					reference;
	typedef random_access_iterator_tag	iterator_category;
};

// Specialization for <T const *>:
template <class Iterator>
struct iterator_traits<Iterator const*>
{
	typedef ptrdiff_t					difference_type;
	typedef Iterator					value_type;
	typedef Iterator*					pointer;
	typedef Iterator&					reference;
	typedef random_access_iterator_tag	iterator_category;
};
