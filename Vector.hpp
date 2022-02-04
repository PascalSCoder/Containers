#pragma once

#include <algorithm>
#include <iostream>
#include <limits>

template< class T, class Alloc = std::allocator<T> >
class vector
{
public:

#pragma region Type definitions

/*
	value_type	The first template parameter (T)	
	allocator_type	The second template parameter (Alloc)	defaults to: allocator<value_type>
	reference	allocator_type::reference	for the default allocator: value_type&
	const_reference	allocator_type::const_reference	for the default allocator: const value_type&
	pointer	allocator_type::pointer	for the default allocator: value_type*
	const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
	iterator	a random access iterator to value_type	convertible to const_iterator
	const_iterator	a random access iterator to const value_type	
	reverse_iterator	reverse_iterator<iterator>	
	const_reverse_iterator	reverse_iterator<const_iterator>	
	difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
*/

	typedef T					value_type;
	typedef Alloc				allocator_type;
	typedef value_type&			reference;
	typedef value_type const&	const_reference;
	// typedef ...					iterator;
	// typedef ...					const_iterator;
	// typedef ...					reverse_iterator;
	// typedef ...					const_reverse_iterator;
	// typedef ...					difference_type;
	typedef size_t				size_type;

#pragma endregion

#pragma region Constructors/Destructor

	// default (1)
	vector() : _size(0), _capacity(0)
	{
	}

	// fill (2)	
	explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
	{
		(void)alloc;

		// _data = new value_type[n];
		Realloc(n);
		_size = n;
		std::memset(_data, val, sizeof(value_type) * n);
	}

	// range (3)
	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	{
		(void)alloc;

		while (first != last)
		{
			push_back(*first);
			first++;
		}
	}

	// copy (4)
	vector(const vector& ref);

	~vector()
	{
		delete[] _data;
	}

#pragma endregion

#pragma region Operator overloads

	reference operator[] (size_type n)
	{
		return _data[n];
	}

	const_reference operator[] (size_type n) const
	{
		return _data[n];
	}

#pragma endregion

	void push_back(const value_type& val)
	{
		if (_size == _capacity)
			Realloc(_capacity == 0 ? 1 : _capacity * 2);
		// add data to back
		_data[_size] = val;
		_size++;
	}

	size_type size() const
	{
		return _size;
	}

	size_type capacity() const
	{
		return _capacity;
	}

	size_type max_size() const
	{
		// why is this output different from std::vector?
		return std::numeric_limits<size_type>::max();
	}

	/*
		Change size
		Resizes the container so that it contains n elements.

		If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).

		If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

		If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

		Notice that this function changes the actual content of the container by inserting or erasing elements from it.
	*/
	void resize(size_type n, value_type val = value_type())
	{
		if (n > _capacity)
			Realloc(n);
		while (_size < n)
			push_back(val);
		while (_size > n)
		{
			// destroy objects?
			_size--;
		}
	}

private:
	value_type*	_data;
	size_type	_size;
	size_type	_capacity;

	void	Realloc(size_type newSize)
	{
		// edge case with overflow?
		// are we allowed to call std::realloc?

		std::cout << "realloc from: " << _capacity << " to " << newSize << std::endl;
		_capacity = newSize;
		value_type* data = new value_type[_capacity];
		std::memcpy(data, _data, _size * sizeof(value_type));
		delete[] _data;
		_data = data;
	}
};
