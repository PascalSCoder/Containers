#pragma once

#include <Vector.hpp>
#include "PascalTest.hpp"
#include <vector>

#include <string>

template<class T>
class VectorTest : public PascalTest<VectorTest<T> >
{
	typedef struct Check<VectorTest<T> > SubCheck; // also works with Check<VectorTest>, seems weird?

private:

	std::string to_string(size_t n) const
	{
		std::string str;

		while (1)
		{
			str.insert(str.begin(), n % 10 + '0');
			if ((n /= 10) == 0)
				break;
		}
		return str;
	}

	ft::vector<T> _ftVec;
	std::vector<T> _stdVec;

	void AddChecks();

#pragma region Checks

	// Returns whether ft::vector and std::vector are equal in size.
	bool CheckSize() const
	{
		return _ftVec.size() == _stdVec.size();
	}

	bool CheckCapacity() const
	{
		if (!(_ftVec.capacity() == _stdVec.capacity()))
			throw std::runtime_error(to_string(_ftVec.capacity()) + "/" + to_string(_stdVec.capacity()));
		return _ftVec.capacity() == _stdVec.capacity();
	}

	bool CheckData() const
	{
		for (size_t i = 0; i < _stdVec.size(); i++)
		{
			if (_ftVec[i] != _stdVec[i])
				return false;
		}
		return true;
	}

#pragma endregion


public:
	VectorTest()
	{
		AddChecks();
	}

#pragma region API

	void ConstructIter(T* first, T* last)
	{
		_ftVec = ft::vector<T>(first, last);
		_stdVec = std::vector<T>(first, last);
	}

	// Clear the currently stored vectors.
	void Clear()
	{
		_ftVec = ft::vector<T>();
		_stdVec = std::vector<T>();
	}

	// Push a number to the currently stored vectors.
	void push_back(T const& value)
	{
		_ftVec.push_back(value);
		_stdVec.push_back(value);
	}

	// Pop a number from the currently stored vectors.
	void pop_back()
	{
		_ftVec.pop_back();
		_stdVec.pop_back();
	}

	// Insert a number in the currently stored vectors.
	void insert(size_t position, T const& val)
	{
		_ftVec.insert(_ftVec.begin() + position, val);
		_stdVec.insert(_stdVec.begin() + position, val);
	}

	void insert(size_t position, size_t n, T const& val)
	{
		_ftVec.insert(_ftVec.begin() + position, n, val);
		_stdVec.insert(_stdVec.begin() + position, n, val);
	}

	void insert(size_t position, T* begin, T* end)
	{
		_ftVec.insert(_ftVec.begin() + position, begin, end);
		_stdVec.insert(_stdVec.begin() + position, begin, end);
	}

	void assign(size_t n, T const& val)
	{
		_ftVec.assign(n, val);
		_stdVec.assign(n, val);
	}

	void assign(T* first, T* last)
	{
		_ftVec.assign(first, last);
		_stdVec.assign(first, last);
	}

	void erase(size_t index)
	{
		_ftVec.erase(_ftVec.begin() + index);
		_stdVec.erase(_stdVec.begin() + index);
	}

	void erase(size_t index, size_t n)
	{
		_ftVec.erase(_ftVec.begin() + index, _ftVec.begin() + index + n);
		_stdVec.erase(_stdVec.begin() + index, _stdVec.begin() + index + n);
	}

#pragma endregion

	template<class TT>
	friend std::ostream& operator<<(std::ostream& os, VectorTest<TT> const& ref);
};


template<class T>
std::ostream& operator<<(std::ostream& os, VectorTest<T> const& ref)
{
	{
		typename std::vector<T>::const_iterator first = ref._stdVec.begin();
		typename std::vector<T>::const_iterator last = ref._stdVec.end();

		os << "std (" << ref._stdVec.size() << "/" << ref._stdVec.capacity() << "): ";
		while (first != last)
		{
			os << "[" << *first << "]";
			first++;
		}
		os << std::endl;
	}
	{
		typename ft::vector<T>::const_iterator first = ref._ftVec.begin();
		typename ft::vector<T>::const_iterator last = ref._ftVec.end();

		os << "ft (" << ref._ftVec.size() << "/" << ref._ftVec.capacity() << "): ";
		// return os;
		while (first != last)
		{
			os << "[" << *first << "]";
			first++;
		}
	}
	return os;
}


#include "GEN_VectorChecks.tpp"
