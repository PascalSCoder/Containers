#pragma once

#include <vector>

template<class T, class Container = std::vector<T> >
class stack : private Container
{
	typedef Container			base;
	typedef typename base::size_type	size_type;
	typedef typename base::value_type	value_type;

public:
	// Returns whether the stack is empty: i.e. whether its size is zero.
	bool empty() const
	{
		return base::empty();
	}

	// Returns the number of elements in the stack.
	size_type size() const
	{
		return base::size();
	}

	// Returns a reference to the top element in the stack.
	value_type& top()
	{
		return base::back();
	}

	// Returns a reference to the top element in the stack.
	const value_type& top() const
	{
		return base::back();
	}

	// Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.
	void push (const value_type& val)
	{
		base::push_back(val);
	}

	// Removes the element on top of the stack, effectively reducing its size by one.
	void pop()
	{
		base::pop_back();
	}

};

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

// relational operators (stack)

	// if (lhs.size() != rhs.size())
	// 	return false;
	// for (size_t i = 0; i < lhs.size(); i++)
	// {
	// 	if (lhs[i] != rhs[i])
	// 		return false;
	// }
	// return true;
