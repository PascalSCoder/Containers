#pragma once

#include <vector>

namespace ft
{

template<class T, class Container = std::vector<T> >
class stack : private Container
{
	typedef Container							container_type;
	typedef typename container_type::size_type	size_type;
	typedef typename container_type::value_type	value_type;

public:
	// Returns whether the stack is empty: i.e. whether its size is zero.
	bool empty() const
	{
		return container_type::empty();
	}

	// Returns the number of elements in the stack.
	size_type size() const
	{
		return container_type::size();
	}

	// Returns a reference to the top element in the stack.
	value_type& top()
	{
		return container_type::back();
	}

	// Returns a reference to the top element in the stack.
	const value_type& top() const
	{
		return container_type::back();
	}

	// Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.
	void push (const value_type& val)
	{
		container_type::push_back(val);
	}

	// Removes the element on top of the stack, effectively reducing its size by one.
	void pop()
	{
		container_type::pop_back();
	}

	template <class V, class C>
	friend bool operator==(const stack<V,C>& lhs, const stack<V,C>& rhs);
	template <class V, class C>
	friend bool operator!=(const stack<V,C>& lhs, const stack<V,C>& rhs);
	template <class V, class C>
	friend bool operator< (const stack<V,C>& lhs, const stack<V,C>& rhs);
	template <class V, class C>
	friend bool operator<=(const stack<V,C>& lhs, const stack<V,C>& rhs);
	template <class V, class C>
	friend bool operator> (const stack<V,C>& lhs, const stack<V,C>& rhs);
	template <class V, class C>
	friend bool operator>=(const stack<V,C>& lhs, const stack<V,C>& rhs);
};

#pragma region Comparison Overloads

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (static_cast<Container>(lhs) == static_cast<Container>(rhs));
	}

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (static_cast<Container>(lhs) != static_cast<Container>(rhs));
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (static_cast<Container>(lhs) < static_cast<Container>(rhs));
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (static_cast<Container>(lhs) <= static_cast<Container>(rhs));
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (static_cast<Container>(lhs) > static_cast<Container>(rhs));
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (static_cast<Container>(lhs) >= static_cast<Container>(rhs));
	}

#pragma endregion

}
