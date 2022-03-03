#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

#include "../utils/iterator_traits.hpp"
#include "../utils/reverse_iterator.hpp"

namespace ft
{

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

	typedef T										value_type;
	typedef Alloc									allocator_type;
	typedef value_type&								reference;
	typedef value_type const&						const_reference;
	typedef value_type*								pointer;
	typedef const value_type*						const_pointer;
	typedef T*										iterator;
	typedef T const*								const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator; // reverse_iterator<const_iterator> const instead?
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;

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
		AssignInternal(0, n, val);
	}

	// range (3)
	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc)
	{
		AssignInternal(0, first, last);
	}

	// copy (4)
	vector(const vector& ref) : _size(0), _capacity(0), _alloc(ref._alloc)
	{
		*this = ref;
	}

	vector<T>& operator=(vector<T> const& ref)
	{
		clear();
		AssignInternal(0, const_cast<iterator>(ref.begin()), const_cast<iterator>(ref.end()));
		return *this;
	}

	~vector()
	{
		if (_capacity > 0)
			_alloc.deallocate(_data, _capacity);
	}

#pragma endregion

#pragma region Modifiers

	// range (1)
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		clear();
		AssignInternal(0, first, last);
	}

	// fill (2)
	void assign (size_type n, const value_type& val)
	{
		clear();
		AssignInternal(0, n, val);
	}

	void push_back(const value_type& val)
	{
		MemReserve(_size + 1);

		_alloc.construct(_data + _size, val);
		_size++;
	}

	void pop_back()
	{
		_size--;
		_alloc.destroy(&_data[_size]);
	}

	// single element (1)
	// Returns an iterator that points to the first of the newly inserted elements.
	iterator insert (iterator position, const value_type& val)
	{
		size_type i = position - _data;
		MemReserve(_size + 1);
		MoveData(i, 1);
		AssignInternal(i, 1, val);
		return _data + i;
	}

	// fill (2)
	void insert (iterator position, size_type n, const value_type& val)
	{
		size_type i = position - _data;
		MemReserve(_size + n);
		MoveData(i, n);
		AssignInternal(i, n, val);
	}

	// range (3)
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last)
	{
		size_type i = position - _data;
		size_type n = last - first;
		MemReserve(_size + n);
		MoveData(i, n);
		AssignInternal(i, first, last);
	}

	iterator erase(iterator position)
	{
		_alloc.destroy(position);
		std::memmove(position, position + 1, (_data + _size - position) * sizeof(value_type));
		_size--;

		return position + 1;
	}

	iterator erase(iterator first, iterator last)
	{
		size_type n = last - first;
		while (first != last)
		{
			_alloc.destroy(first);
			first++;
		}
		std::memmove(first - n, first, (end() - first) * sizeof(value_type));
		_size -= n;
		return first - n;
	}

	void swap(vector& x)
	{
		T*	data = _data;
		size_type size = _size;
		size_type capacity = _capacity;

		_data = x._data;
		_size = x._size;
		_capacity = x._capacity;

		x._data = data;
		x._size = size;
		x._capacity = capacity;
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
		MemReserve(n);
		while (_size > n)
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}
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
		MemReserve(n);
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
		return reverse_iterator(end() - 1);
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end() - 1);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin() - 1);
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin() - 1);
	}

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

#pragma region Friend functions

	template <class TT, class Allocc>
	friend bool operator==(const vector<TT,Allocc>& lhs, const vector<TT,Allocc>& rhs);
	template <class TT, class Allocc>
	friend bool operator!=(const vector<TT,Allocc>& lhs, const vector<TT,Allocc>& rhs);
	template <class TT, class Allocc>
	friend bool operator> (const vector<TT,Allocc>& lhs, const vector<TT,Allocc>& rhs);
	template <class TT, class Allocc>
	friend bool operator>=(const vector<TT,Allocc>& lhs, const vector<TT,Allocc>& rhs);
	template <class TT, class Allocc>
	friend bool operator< (const vector<TT,Allocc>& lhs, const vector<TT,Allocc>& rhs);
	template <class TT, class Allocc>
	friend bool operator<=(const vector<TT,Allocc>& lhs, const vector<TT,Allocc>& rhs);

#pragma endregion

private:
	value_type*		_data;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;

	// If neccessary, increases capacity to req, otherwise does nothing.
	void MemReserve(size_type req)
	{
		if (req <= _capacity) // capacity is large enough
			return;
		req = std::max(_capacity * 2, req);

		value_type* newData = _alloc.allocate(req);
		if (_capacity != 0) // if _data was already allocated
		{
			std::memcpy(newData, _data, _size * sizeof(value_type));
			_alloc.deallocate(_data, _capacity);
		}

		_data = newData;
		_capacity = req;
	}

	// If full capacity is used, increase capacity.
	// void MemReserve()
	// {
	// 	if (_capacity == 0)
	// 		MemReserve(1); // [_data = allocate(1); _capacity = 1;] would be faster, but reusing this function is nice :)
	// 	else if (_size == _capacity) // size should never by higher than capacity, so >= should not be neccessary
	// 		MemReserve(_capacity * 2);
	// 	else if (_size > _capacity) // TEMPORARY DEV CHECK WHICH SHOULD NOT BE REACHED
	// 		throw std::runtime_error("Size exceeded capacity exception.");
	// }

	// Moves all data, starting at index by n elements.
	// Returns a pointer to index, which now has 'garbage values'.
	// Caution: This function does not allocate when neccessary!
	iterator MoveData(size_type index, size_type n)
	{
		iterator first = begin();
		iterator last = end();
		first += index;
		std::memmove(first + n, first, (last - first) * sizeof(value_type));
		return first;
	}

	void AssignInternal(size_type index, size_type n, const value_type& val)
	{
		MemReserve(_size + n);

		_size += n;
		n += index;
		for (size_type i = index; i < n; i++)
		{
			_alloc.construct(_data + i, val);
		}
	}

	void AssignInternal(size_type index, iterator first, iterator last)
	{
		MemReserve(_size + (last - first));
		
		while (first != last)
		{
			_alloc.construct(_data + index, *first);
			++_size;
			++first;
			++index;
		}
	}

};


// CREATE MORE EFFICIENT COMPARISON FUNCTIONS

#pragma region Comparison Overloads

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return true;
		}
		if (lhs.size() > rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs > rhs)
			return true;
		else if(lhs == rhs)
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		for (size_t i = 0; i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return true;
		}
		if (lhs.size() < rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs < rhs)
			return true;
		else if (lhs == rhs)
			return true;
		return false;
	}

#pragma endregion

}
