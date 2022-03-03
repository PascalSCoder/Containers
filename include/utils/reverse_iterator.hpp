#pragma once

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{

template <class Iterator>
struct reverse_iterator
{
	typedef typename iterator_traits<Iterator>::difference_type	difference_type;
	typedef typename iterator_traits<Iterator>::reference		reference;
	typedef typename iterator_traits<Iterator>::pointer			pointer;

private:
	pointer _iterator;

public:

#pragma region Constructors/Destructors

	// default (1)
	reverse_iterator()
	{
	}

	// initialization (2)
	reverse_iterator (Iterator it) : _iterator(it) // explicit keyword removed
	{
	}

	// copy (3)
	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& ref)
	{
		*this = ref;
	}

	~reverse_iterator()
	{
	}

#pragma endregion

#pragma region Operator Overloads

	reverse_iterator& operator=(const reverse_iterator& ref)
	{
		_iterator = ref._iterator;
		return *this;
	}

	reference operator*() const
	{
		return *(this->_iterator);
	}

	reverse_iterator operator+(difference_type n) const
	{
		return this->_iterator - n;
	}

	reverse_iterator& operator++()
	{
		this->_iterator--;
		return *this;
	}

	reverse_iterator  operator++(int)
	{
		reverse_iterator it(*this);
		this->_iterator--;
		return it;
	}

	reverse_iterator& operator+=(difference_type n)
	{
		return *(_iterator -= n);
	}

	reverse_iterator operator-(difference_type n) const
	{
		return _iterator + n;
	}

	reverse_iterator& operator--()
	{
		return _iterator++;
	}

	reverse_iterator  operator--(int)
	{
		reverse_iterator it(*this);
		this->_iterator--;
		return it;
	}

	reverse_iterator& operator-=(difference_type n)
	{
		return _iterator += n;
	}

	pointer operator->() const
	{
		return _iterator;
	}

	reference operator[](difference_type n) const
	{
		return _iterator[n];
	}

	#pragma endregion

	template<class Iter>
	friend bool operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template<class Iter>
	friend bool operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template<class Iter>
	friend bool operator> (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template<class Iter>
	friend bool operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template<class Iter>
	friend bool operator< (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
	template<class Iter>
	friend bool operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

};

#pragma region Comparison Overloads

	template<class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs._iterator == rhs._iterator;
	}

	template<class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs._iterator != rhs._iterator;
	}

	template<class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs._iterator > rhs._iterator;
	}

	template<class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs._iterator >= rhs._iterator;
	}

	template<class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs._iterator < rhs._iterator;
	}

	template<class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs._iterator <= rhs._iterator;
	}

	#pragma endregion

}



// template <class Category, class T, class Distance = ptrdiff_t,
// 		class Pointer = T*, class Reference = T&>
// struct iterator
// {
// 	typedef T			value_type;
// 	typedef Distance	difference_type;
// 	typedef Pointer		pointer;
// 	typedef Reference	reference;
// 	typedef Category	iterator_category;

// protected:
// 	pointer	_pointer;

// 	iterator(Iterator& ref)
// 	{
// 		std::cout << "iterator base ctor called" << std::endl;
// 	}
// };




// template <class Category, class T, class Distance = ptrdiff_t,
// 		class Pointer = T*, class Reference = T&>
// template <class Iterator>
// struct reverse_iterator : public iterator<
// 							typename iterator_traits<Iterator>::iterator_category,
// 							typename iterator_traits<Iterator>::value_type,
// 							typename iterator_traits<Iterator>::difference_type,
// 							typename iterator_traits<Iterator>::pointer,
// 							typename iterator_traits<Iterator>::reference>
// {
// public:
// 	typedef typename iterator_traits<Iterator>::difference_type	difference_type;
// 	typedef typename iterator_traits<Iterator>::reference		reference;
// 	typedef typename iterator_traits<Iterator>::pointer			pointer;
