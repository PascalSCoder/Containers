#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

#include "iterator_traits.hpp"
#include "iterator.hpp"

// #include <iterator>

template< class T, class Alloc = std::allocator<T> >
class vector
{
public:

#pragma region Type definitions

/*
	value_type				The first template parameter (T)	
	allocator_type			The second template parameter (Alloc)	defaults to: allocator<value_type>
	reference				allocator_type::reference	for the default allocator: value_type&
	const_reference			allocator_type::const_reference	for the default allocator: const value_type&
	pointer					allocator_type::pointer	for the default allocator: value_type*
	const_pointer			allocator_type::const_pointer	for the default allocator: const value_type*
	iterator				a random access iterator to value_type	convertible to const_iterator
	const_iterator			a random access iterator to const value_type	
	reverse_iterator		reverse_iterator<iterator>	
	const_reverse_iterator	reverse_iterator<const_iterator>	
	difference_type			a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	size_type				an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
*/

	typedef T					value_type;
	typedef Alloc				allocator_type;
	typedef value_type&			reference;
	typedef value_type const&	const_reference;
	typedef value_type*			pointer;
	typedef const value_type*	const_pointer;

	typedef T*					iterator;
	typedef T const*			const_iterator;

	// experimental!

	// typedef iterator<random_access_iterator_tag, pointer>	iterator;
	// typedef typename iterator<random_access_iterator_tag, T>::pointer	iterator;

	// typedef reverse_iterator<random_access_iterator_tag, T>		reverse_iterator;

	typedef reverse_iterator<iterator>		reverse_iterator;
	// typedef ...					const_reverse_iterator;

	typedef ptrdiff_t			difference_type;
	typedef size_t				size_type;

#pragma endregion

#pragma region Constructors/Destructor

	// default (1)
	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc)
	{
	}

	// fill (2)	
	explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) : _size(0), _capacity(n), _alloc(alloc)
	{
		_data = _alloc.allocate(n);
		for (size_t i = 0; i < n; i++)
		{
			_alloc.construct(&(_data[i]), val);
			_size++;
		}
	}

	// range (3)
	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc)
	{
		while (first != last)
		{
			push_back(*first);
			first++;
		}
	}

	// copy (4)
	vector(const vector& ref)
	{
		(void)ref;
		throw std::runtime_error("Not implemented yet!");
	}

	~vector()
	{
		_alloc.deallocate(_data, _capacity);
	}

#pragma endregion

#pragma region Operator overloads

#pragma endregion

#pragma region Modifiers

// UNFINISHED
	// range (1)
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		(void)first;
		(void)last;
	}

// UNFINISHED
	// fill (2)
	void assign (size_type n, const value_type& val)
	{
		(void)n;
		(void)val;
	}

	void push_back(const value_type& val)
	{
		if (_size == _capacity)
			Realloc(_capacity == 0 ? 1 : _capacity * 2);

		// add data to back
		_data[_size] = val;
		_size++;
	}

	void pop_back()
	{
		_size--;
		_alloc.destroy(&_data[_size]);
	}

// UNFINISHED
	// single element (1)
	iterator insert (iterator position, const value_type& val)
	{
		(void)position;
		(void)val;
	}

// UNFINISHED
	// fill (2)
	void insert (iterator position, size_type n, const value_type& val)
	{
		(void)position;
		(void)n;
		(void)val;
	}

// UNFINISHED
	// range (3)
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last)
	{
		(void)position;
		(void)first;
		(void)last;
	}

// UNFINISHED
	iterator erase(iterator position)
	{
		_alloc.destroy(position);
		std::cout << _data + _size - position << std::endl;
		std::memmove(position, position + 1, (_data + _size) - position);
		return position + 1;
	}

// UNFINISHED
	iterator erase(iterator first, iterator last)
	{
		while (first < last)
		{
			_alloc.destroy(first);
			first++;
		}
		// move data
	}

// UNFINISHED / UNTESTED
	void swap(vector& x)
	{
		vector tmp = x;
		x = *this;
		*this = tmp;
	}

	void clear()
	{
		while (_size > 0)
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}
	}

#pragma endregion

#pragma region Capacity

	size_type size() const
	{
		return _size;
	}

	size_type max_size() const
	{
		return _alloc.max_size();
	}

	void resize(size_type n, value_type val = value_type())
	{
		while (_size > n)
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}
		if (n > _capacity)
			n > _capacity * 2 ? Realloc(n) : Realloc(_capacity * 2);
		while (_size < n)
		{
			_alloc.construct(&_data[_size], val);
			_size++;
		}
	}

	size_type capacity() const
	{
		return _capacity;
	}

	bool empty() const
	{
		return _size == 0;
	}

	void reserve (size_type n)
	{
		if (n > _capacity)
			Realloc(n);
	}

#pragma endregion

#pragma region Iterators

/*
	begin	Return iterator to beginning (public member function )
	end		Return iterator to end (public member function )
	rbegin	Return reverse iterator to reverse beginning (public member function )
	rend	Return reverse iterator to reverse end (public member function )
*/
	iterator begin()
	{
		return _data;
	}

	const_iterator begin() const
	{
		return _data;
	}

	iterator end()
	{
		return _data + _size;
	}

	const_iterator end() const
	{
		return _data + _size;
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	// const_reverse_iterator rbegin()
	// {
	// }

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
		// return _data + _size;
	}

	// const_reverse_iterator rend()
	// {
	// }

#pragma endregion

#pragma region Element Access

	reference front()
	{
		return *_data;
	}

	const_reference front() const
	{
		return *_data;
	}

	reference back()
	{
		return *(_data + (_size - 1));
	}

	const_reference back() const
	{
		return *(_data + (_size - 1));
	}

	reference at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("vector::at");
		return *(_data[n]);
	}

	const_reference at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("vector::at");
		return *(_data[n]);
	}

	reference operator[](size_type n)
	{
		return _data[n];
	}

	const_reference operator[](size_type n) const
	{
		return _data[n];
	}

#pragma endregion

	allocator_type get_allocator() const
	{
		return _alloc;
	}

private:
	value_type*		_data;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;

	void	Realloc(size_type n)
	{
		value_type* newData = _alloc.allocate(n);
		std::memcpy(newData, _data, _size * sizeof(value_type));
		_alloc.deallocate(_data, _capacity);

		_data = newData;
		_capacity = n;
	}

};