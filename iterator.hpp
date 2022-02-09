#pragma once

#include <iostream>
#include "iterator_traits.hpp"

template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;

protected:
	pointer	_pointer;
};

// template <class Category, class T, class Distance = ptrdiff_t,
// 		class Pointer = T*, class Reference = T&>
template <class Iterator>
struct reverse_iterator : public iterator<
							typename iterator_traits<Iterator>::iterator_category,
							typename iterator_traits<Iterator>::value_type,
							typename iterator_traits<Iterator>::difference_type,
							typename iterator_traits<Iterator>::pointer,
							typename iterator_traits<Iterator>::reference>
{
public:
	typedef typename iterator_traits<Iterator>::difference_type	difference_type;
	typedef typename iterator_traits<Iterator>::reference		reference;
	typedef typename iterator_traits<Iterator>::pointer			pointer;

	reverse_iterator() : _iterator()
	{
	}

	explicit reverse_iterator(Iterator ref) : _iterator(ref)
	{
	}

// If this copy ctor is uncommented, a lot errors will occur.
// 1. Why?
// 2. Do I need this copy ctor?
	// reverse_iterator(reverse_iterator &ref) : _iterator(ref)
	// {
	// }

	reverse_iterator& operator=(const reverse_iterator& ref)
	{
		_iterator = ref.base();
		return *this;
	}

	reference operator*() const
	{
		return *_iterator;
		// return *(this->_pointer - _offset);
	}

	reverse_iterator operator+(difference_type n) const
	{
		return _iterator - n;
		// reverse_iterator copy = *this;
		// copy._offset += n;
		// return copy;
	}

	reverse_iterator& operator++()
	{
		return _iterator--;
		// _offset++;
		// return *this;
	}

	reverse_iterator  operator++(int)
	{
		return --_iterator;
		// reverse_iterator copy(*this);
		// _offset++;
		// return copy;
	}

	reverse_iterator& operator+=(difference_type n)
	{
		return *(_iterator -= n);
		// _offset += n;
		// return *this;
	}

	reverse_iterator operator-(difference_type n) const
	{
		return _iterator + n;
		// reverse_iterator copy = *this;
		// copy._offset -= n;
		// return copy;
	}

	reverse_iterator& operator--()
	{
		return _iterator++;
		// _offset--;
		// return *this;
	}

	reverse_iterator  operator--(int)
	{
		return _iterator++;
		// reverse_iterator copy(*this);
		// _offset--;
		// return copy;
	}

	reverse_iterator& operator-=(difference_type n)
	{
		return _iterator += n;
		// _offset -= n;
		// return *this;
	}

	pointer operator->() const
	{
		return *(this->_pointer);
	}

	reference operator[](difference_type n) const
	{
		return _iterator[n];
		// return *(this->_pointer - _offset - n);
	}

private:
	Iterator _iterator;
	// difference_type	_offset;
};
